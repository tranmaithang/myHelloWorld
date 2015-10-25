#include <iostream>
#include <vector>
using namespace std;

//-----------------Prototype------------------------
double scalaire(vector<double> u, vector<double> v);
vector<double> vector_element(int n);
//--------------------------------------------------

int main ()
{
	vector<double> v1;
	vector<double> v2;
	
	int N_max(5);
	
	int n;
	do {
		cout << "Quelle taille pour les vecteurs ? ";
		cin >> n;
	} while (n > N_max);
	
	v1 = vector_element(n);
	v2 = vector_element(n);
	
	cout << scalaire(v1,v2) << endl;
	return 0;
}

//Fonction qui calcule le produit scalaire de 2 vector
double scalaire(vector<double> u, vector<double> v)
{
	double prod (0.0);
	for (size_t i(0); i < u.size(); ++i) {
			prod += u[i] * v[i];
	}
	return prod;
}

vector<double> vector_element(int n)
{
	vector<double> v(n);
	
	cout << "Entrez les composantes du vector: " << endl;
	for (int i(0); i < n; ++i) {
		cout << "Entrez l'element " << i << ": ";
		cin >> v[i];
	}
	return v;
}
