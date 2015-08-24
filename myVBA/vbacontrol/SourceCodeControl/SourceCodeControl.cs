using System;
using System.IO;
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
            /*** Build log ***/
            System.Console.ForegroundColor = System.ConsoleColor.Green;
            System.Console.WriteLine("Extract macro (VBA) code from Excel" + "\n");

            // Get current folder and parent folder
            string currentDir = System.IO.Directory.GetCurrentDirectory();
            string parentDir = System.IO.Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(currentDir))));

            // Obtain selected files in the directory path
            string[] addinArray = System.IO.Directory.GetFiles(System.IO.Path.Combine(parentDir, "addins"), "*.xlam");
            string[] sampleArray = System.IO.Directory.GetFiles(System.IO.Path.Combine(parentDir, "samples"), "*.xlsm");
            string[] mergeArray = addinArray.Concat(sampleArray).ToArray();

            // Process all files in the directory passed in
            foreach (string filePath in mergeArray)
            {
                Microsoft.Office.Interop.Excel.Application excelApp = new Microsoft.Office.Interop.Excel.Application();
                Microsoft.Office.Interop.Excel.Workbook excelWb = excelApp.Workbooks.Open(filePath);

                /*** Build log ***/
                System.Console.ForegroundColor = System.ConsoleColor.Green;
                System.Console.WriteLine("Process file '{0}'", excelWb.Name); 

                // Process all components in the workbook passed in
                foreach (Microsoft.Vbe.Interop.VBComponent vbComp in excelWb.VBProject.VBComponents)
                {
                    if (vbComp.CodeModule.CountOfLines > 0)
                    {
                        // Code module name
                        string moduleName = vbComp.Name;

                        // Code module name with extension
                        switch (vbComp.Type)
                        {
                            case Microsoft.Vbe.Interop.vbext_ComponentType.vbext_ct_ClassModule:
                                moduleName += ".cls";
                                break;
                            case vbext_ComponentType.vbext_ct_StdModule:
                                moduleName += ".bas";
                                break;
                            case Microsoft.Vbe.Interop.vbext_ComponentType.vbext_ct_MSForm:
                                moduleName += ".frm";
                                break;
                            default:
                                moduleName = String.Empty;
                                break;
                        }

                        // Export code module
                        if (!String.IsNullOrEmpty(moduleName))
                        {
                            string wbName = System.IO.Path.GetFileNameWithoutExtension(filePath);
                            string wbExtension = System.IO.Path.GetExtension(filePath);

                            // Get composed file directory
                            string composedFileDir;
                            if (wbExtension == ".xlam")
                                composedFileDir = System.IO.Path.Combine(Path.Combine(Path.Combine(parentDir, "_reference"), "addins"), wbName);
                            else
                                composedFileDir = System.IO.Path.Combine(Path.Combine(Path.Combine(parentDir, "_reference"), "samples"), wbName);

                            System.IO.Directory.CreateDirectory(composedFileDir);

                            // Get composed file path
                            string composedFilePath = System.IO.Path.Combine(composedFileDir, moduleName);
                            
                            // Export composed file
                            vbComp.Export(composedFilePath);

                            /*** Build log ***/
                            System.Console.ForegroundColor = System.ConsoleColor.Gray;
                            System.Console.WriteLine("Extract code module '{0}' in {1}",  moduleName, composedFilePath);
                        }
                    }
                }

                // Clean up COM objects
                excelWb.Close();
                System.Runtime.InteropServices.Marshal.ReleaseComObject(excelWb);
                excelApp.Quit();
                System.Runtime.InteropServices.Marshal.ReleaseComObject(excelApp);
            }

            /*** Build log ***/
            System.Console.WriteLine("\n");
            System.Console.ForegroundColor = System.ConsoleColor.Green;
            System.Console.WriteLine("Build sucess !");
            System.Console.ReadLine();
        }
    }
}
