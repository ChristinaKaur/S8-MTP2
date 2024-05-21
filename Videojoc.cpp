#include <iostream>
#include "Videojoc.h"

using namespace std;

// CONSTRUCTORS
Videojoc::Videojoc() {
	// Pre: --
	// Post: Videojoc inicialitzada
	a_nom = "";
	a_unitats = 0;
	a_data_venda = Data();
}

Videojoc::Videojoc(string nom, int unitats, Data data) {
	// Pre: --
	// Post: Videojoc inicialitzada amb dades passades per funcio
	a_nom = nom;
	a_unitats = unitats;
	a_data_venda = data;
}

Videojoc::Videojoc(const Videojoc& v) {
	// Pre: --
	// Post: Videojoc inicialitzada amb dades de v
	a_nom = v.a_nom;
	a_unitats = v.a_unitats;
	a_data_venda = v.a_data_venda;
}

// CONSULTORS
void Videojoc::mostrar() const {
	// Pre: --
	// Post: mostra per pantalla informacio de del videojoc
	cout << a_nom << ": " << a_unitats << " - " << a_data_venda << endl;
}

bool Videojoc::joc_previ(const Data& data) const {
	// Pre:--;
	// Post: ens diu si la data de venda del videojoc actual es previa a data  
	return data > a_data_venda;
}

bool Videojoc::mateix_nom(Videojoc v) const {
	// Pre:--; Post: ens diu si el videojoc actual te el mateix nom
	return v.a_nom == a_nom;
}

// MODIFICADORS 
void Videojoc::llegir_videojoc() {
	// Pre: --
	// Post: llegir per teclat informacio de del videojoc
	cin.ignore();
	getline(cin, a_nom);
	cin >> a_unitats >> a_data_venda;
}

void Videojoc::modificar(const Videojoc v) {
	// Pre: --
	// Post: a_unitats +=v.a_unitats i si data de venda del videojoc actual no és posterior a la de v es modifica
	if (a_data_venda < v.a_data_venda)
		a_data_venda = v.a_data_venda;
	a_unitats += v.a_unitats;
}

// OPERADORS REDEFINITS 
bool Videojoc::operator==(const Videojoc& v) const {
	// Pre: --
	// Post: retorna cert si videojoc actual es igual a v
	return a_nom == v.a_nom and a_unitats == v.a_unitats and a_data_venda == v.a_data_venda;
}

bool Videojoc::operator>(const Videojoc& v) const {
	// Pre: --
	// Post: retorna cert si videojoc actual es superior a v
	return (a_nom > v.a_nom) or (a_nom == v.a_nom and a_unitats > v.a_unitats) or (a_nom == v.a_nom and a_unitats == v.a_unitats and a_data_venda > v.a_data_venda);
}

bool Videojoc::operator>=(const Videojoc& v) const {
	// Pre: --
	// Post: retorna cert si videojoc actual es superior o igual a v
	return a_nom > v.a_nom or (a_nom == v.a_nom and a_unitats >= v.a_unitats) or (a_nom == v.a_nom and a_unitats == v.a_unitats and a_data_venda >= v.a_data_venda);
}

void Videojoc::operator=(const Videojoc& v) {
	// Pre: --
	// Post: videojoc actual = v
	a_nom = v.a_nom;
	a_unitats = v.a_unitats;
	a_data_venda = v.a_data_venda;
}

ostream& operator<<(ostream& o, const Videojoc& v) {
	// Pre: es pot escriure a o; 
	// Post: s’ha escrit la informació de v a o
	o << v.a_nom << ": " << v.a_unitats << " - " << v.a_data_venda;
	return o;
}

istream& operator>>(istream& i, Videojoc& v) {
	// Pre: es pot llegir d’i; 
	// Post: v conté les dades llegides d’i
	getline(i, v.a_nom);
	i >> v.a_unitats >> v.a_data_venda;
	i.ignore(); 
	return i;
}