using System;
using System.IO;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using Microsoft.Office.Interop.Excel;
using Microsoft.Vbe.Interop;

namespace SourceCodeControl
{
    class SourceCodeControl
    {
        static void Main(string[] args)
        {
            // Begin timing
            Stopwatch stopWatch = Stopwatch.StartNew();

            /*** Build log ***/
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("Extract macro (VBA) code from Excel" + "\n");

            // Get current folder and parent folder
            string currentDir = Directory.GetCurrentDirectory();
            string parentDir = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(currentDir))));

            // Obtain selected files in the directory path
            string[] addinArray = Directory.GetFiles(Path.Combine(parentDir, "addins"), "*.xlam");
            string[] sampleArray = Directory.GetFiles(Path.Combine(parentDir, "samples"), "*.xlsm");
            string[] mergeArray = addinArray.Concat(sampleArray).ToArray();

            // Process all files in the directory passed in
            if (mergeArray.Count() != 0)
                ExtractVBACodeFromExcel(mergeArray);
            else
            {
                /*** Build log ***/
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("WARNING: No file avaialble");
                Console.ReadLine();
                Environment.Exit(0);
            }

            // Stop timing
            stopWatch.Stop();

            /*** Build log ***/
            Console.WriteLine("\n");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Build succeeded !");
            Console.ForegroundColor = ConsoleColor.DarkGray;
            Console.WriteLine("Time taken : {0}", stopWatch.Elapsed);
            Console.ReadLine();
            Environment.Exit(0);
        }


        private static void ExtractVBACodeFromExcel(string[] args)
        {
            int counter = 1;
            foreach (string filePath in args)
            {
                Microsoft.Office.Interop.Excel.Application excelApp = null;
                Workbooks excelWbs = null;
                Workbook excelWb = null;

                try
                {
                    // NOTE: Rule for the usage of COM objects in C#: "Never use 2 dots with COM objects"
                    // ex. excelWb = excelApp.Workbooks.Open(filePath) -> not good
                    excelApp = new Microsoft.Office.Interop.Excel.Application();
                    excelWbs = excelApp.Workbooks;
                    excelWb = excelWbs.Open(filePath);

                    /*** Build log ***/
                    Console.ForegroundColor = ConsoleColor.Cyan;
                    Console.WriteLine("{0}> Processing file '{1}'", counter, excelWb.Name);
                    counter += 1;

                    // Process all macros in the workbook passed in
                    foreach (VBComponent vbComponent in excelWb.VBProject.VBComponents)
                    {
                        if (vbComponent.CodeModule.CountOfLines > 0
                            && !string.IsNullOrEmpty(GetFilenameExtension(vbComponent)))
                        {
                            // Set composed file name
                            string moduleName = vbComponent.Name + GetFilenameExtension(vbComponent);

                            // Create reference directory
                            string parentDir = Path.GetDirectoryName(Path.GetDirectoryName(filePath));

                            // Create composed file directory
                            string composedFileDir;
                            if (Path.GetExtension(filePath) == ".xlam")
                                composedFileDir = Path.Combine(Path.Combine(Path.Combine(parentDir, "_reference"), "addins"), excelWb.Name);
                            else
                                composedFileDir = Path.Combine(Path.Combine(Path.Combine(parentDir, "_reference"), "samples"), excelWb.Name);

                            Directory.CreateDirectory(composedFileDir);

                            // Get composed file path
                            string composedFilePath = Path.Combine(composedFileDir, moduleName);

                            // Export composed file
                            vbComponent.Export(composedFilePath);

                            /*** Build log ***/
                            Console.ForegroundColor = ConsoleColor.DarkGray;
                            Console.WriteLine("Extracting code module '{0}' in {1}", moduleName, composedFilePath);
                        }
                    }

                    excelWb.Close();
                    excelApp.Quit();
                }
                finally
                {
                    // Clean up COM objects
                    // ref. https://www.add-in-express.com/creating-addins-blog/2013/11/05/release-excel-com-objects/
                    // ref. http://stackoverflow.com/questions/158706/how-to-properly-clean-up-excel-interop-objects

                    if (excelWb != null) Marshal.ReleaseComObject(excelWb);
                    if (excelWbs != null) Marshal.ReleaseComObject(excelWbs);
                    if (excelApp != null) Marshal.ReleaseComObject(excelApp);

                    GC.Collect();
                    GC.WaitForPendingFinalizers();
                    GC.Collect();
                    GC.WaitForPendingFinalizers();

                    /*** Build log ***/
                    Console.ForegroundColor = ConsoleColor.DarkGray;
                    Console.WriteLine("Releasing COMObject");
                }
            }
        }


        private static string GetFilenameExtension(VBComponent vbComponent)
        {
            string fileNameExtension = string.Empty;
            switch (vbComponent.Type)
            {
                case vbext_ComponentType.vbext_ct_ClassModule:
                    fileNameExtension = ".cls";
                    break;
                case vbext_ComponentType.vbext_ct_StdModule:
                    fileNameExtension = ".bas";
                    break;
                case vbext_ComponentType.vbext_ct_MSForm:
                    fileNameExtension = ".frm";
                    break;
            }

            return fileNameExtension;
        }
    }
}
