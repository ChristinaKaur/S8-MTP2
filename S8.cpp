/****************************************************************************
   Codi de l'exercici de la llista ordenada de videjocs

   Falta posar l'especificacio del programa
 ****************************************************************************/
/*
El programa ha de llegir un fitxer d'entrada que conté les dades de vendes de videojocs i carregar-les en una llista ordenada pel nom del videojoc. 
Si el videojoc ja existeix a la llista, s'ha d'actualitzar la data de la venda més recent i sumar el nombre d'unitats venudes.
*/
#include <iostream>
#include <fstream>
#include "Data.h"
#include "Llista_ord_videojocs.h"

using namespace std;

void llegir_fitxer(Llista_ord_videojocs& ll) {
	// pre: --
	// pos: llegir nom del fitxer per teclat i un cop obert correctament llegir les vendes i inserir-les a la llista ordenada ll
	string nom_f;
	cout << "NOM DEL FITXER:" << endl;
	cin >> nom_f;

	ifstream f_in;
	f_in.open(nom_f.c_str());
	while (!f_in.is_open()) {
		f_in.clear();
		cin >> nom_f;
		f_in.open(nom_f.c_str());
	}

	ll.omplir_llista(f_in);
}

void consulta_existencia_videjoc(const Llista_ord_videojocs& ll) {
	// pre: llista ordenada ll omplerta correctament 
	// pos: comprova si un videojoc forma part de la llista ordenada ll, es repeteix fins que s'entra #
	string nom;
	cout << "INTRODUEIX NOM VIDEOJOC A CONSULTAR (# per finalitzar):" << endl;
	cin.ignore();
	getline(cin, nom);
	while (nom != "#") {
		Videojoc v(nom, 0, Data());

		if (ll.existeix(v)) 
			cout << "Aquest videojoc ha estat venut" << endl;
		else 
			cout << "Aquest videojoc no ha estat venut" << endl;
		
		cout << "INTRODUEIX NOM VIDEOJOC A CONSULTAR (# per finalitzar):" << endl;
		
		getline(cin, nom);
	}
}

int main() {
	Llista_ord_videojocs ll;
	llegir_fitxer(ll); 

	if (not ll.buida()) {
		ll.mostrar();

		int dia, mes, any;
		cout << "INTRODUEIX DATA:" << endl;
		cin >> dia >> mes >> any;
		Data data(dia, mes, any);
		ll.esborra_videojocs_previs_a(data);
		ll.mostrar();

		consulta_existencia_videjoc(ll); // A implementar
	}

	return 0;
}