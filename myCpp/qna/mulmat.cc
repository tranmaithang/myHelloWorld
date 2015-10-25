#include <iostream>
#include <vector>
using namespace std;

//-------------------------PROTOTYPE------------------------------------
vector<vector<double>> lire_matrice();
vector<vector<double>> multiplication(const vector<vector<double>>& Mat1,
                                      const vector<vector<double>>& Mat2);
void  affiche_matrice(const vector<vector<double>> M);
//----------------------------------------------------------------------
                                
int main()
{
	vector<vector<double>> M1(lire_matrice());
	
	vector<vector<double>> M2(lire_matrice());
	
	if (M1[0].size() != M2.size()) {
		cout << "Multiplication de matrices impossible !" << endl;
	}
	else {
		cout << "Resultat" << endl;
		affiche_matrice(multiplication(M1,M2));
	}
	return 0;
}

//Fonction qui permet de saisir une matrice
vector<vector<double>> lire_matrice()
{
	cout << "Saisie d'une matrice" << endl;
	
	unsigned int l; //number of rows
	do {
		cout << "Nombre de lignes : ";
		cin >> l;
	} while (l < 1);
	
	unsigned int c; //number of columns
	do {
		cout << "Nombre de colonnes : ";
		cin >> c;
	} while (c < 1);
	
	vector<vector<double> > M(l, vector<double>(c));	
	for (unsigned int i(0); i < l; ++i) {
		for (unsigned int j(0); j < c; ++j) {
			cout << "M[" << i+1 << "," << j+1 << "] = ";
			cin >> M[i][j];
		}
	}
	return M;
}

//Fonction qui fait la multiplication de 2 matrices
vector<vector<double>> multiplication(const vector<vector<double>>& Mat1,
                                      const vector<vector<double>>& Mat2)
{	
	//Create vector resultat with the same number of rows as Mat1
	//and the same number of columns as Mat2
	vector<vector<double>> resultat(Mat1.size(), vector<double>(Mat2[0].size()));
	
	for (size_t i(0); i < Mat1.size(); ++i) {
		for (size_t j(0); j < Mat2[0].size(); ++j) {
			for (size_t k(0); k < Mat2.size(); ++k) {
				resultat[i][j] += Mat1[i][k] * Mat2[k][j];
			}
		}
	}
	return resultat;
}

//Fonction qui affiche le contenu d'une matrice ligne par ligne.
void  affiche_matrice(const vector<vector<double>> M)
{
	for (size_t i(0); i < M.size(); ++i) {
		for (size_t j(0); j < M[i].size(); ++j) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}
