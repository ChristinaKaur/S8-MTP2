#include <iostream>
#include <string>
#include <fstream>
#include "Llista_ord_videojocs.h"

using namespace std;

// CONSTRUCTORS I DESTRUCTOR 
Llista_ord_videojocs::Llista_ord_videojocs() {
	// Pre: --; Post: cua buida
	a_primer = a_darrer = NULL;
}

Llista_ord_videojocs::Llista_ord_videojocs(const Llista_ord_videojocs& o) {
	// Pre: --; Post: aquesta cua es copia de la Cua o
	a_primer = a_darrer = NULL;
	copia(o);
}

Llista_ord_videojocs::~Llista_ord_videojocs() {
	// Pre: --; Post: memoria alliberada
	// COST: O(n)
	allibera();
}

// CONSULTORS 
bool Llista_ord_videojocs::buida() const {
	// Pre: -- ; Post: retorna cert si la cua es buida; fals en c.c.
	return a_primer == NULL;
}

Videojoc Llista_ord_videojocs::primer() {
	// Pre: cua no buida; 
	// Post: retorna copia del primer string de la cua
	return a_primer->v;
}

void Llista_ord_videojocs::mostrar() const {
	// Pre: cua no buida; 
	// Post: mostra per pantalla tot el contingut de la cua actual    
	cout << "[ VIDEOJOCS VENUTS ]" << endl;
	Node* actual = a_primer;
	while (actual != NULL) {
		cout << actual->v << endl;
		actual = actual->seg;
	}
	cout << endl;
}

bool Llista_ord_videojocs::existeix(Videojoc& v) const {
	// Pre:--; Post: ens diu si e existeix a la llista
	Node* p = a_primer;
	bool fiCerca = false;
	bool trobat = false;
	while ((p != NULL) && (!fiCerca)) {
		if (p->v >= v) {
			fiCerca = true;
			trobat = p->v.mateix_nom(v); 
		}
		else
			p = p->seg;
	}
	return trobat;
}

// MODIFICADORS 
void Llista_ord_videojocs::omplir_llista(ifstream& f_in) {
	// Pre: fitxer f_in obert correctament
	// Post: llista omplerta amb la informació de f_in
	Videojoc v;
	f_in >> v;
	while (!f_in.eof()) {
		inserir(v);
		f_in >> v;
	}
}

void Llista_ord_videojocs::encua(Videojoc& v) {
	// Pre: --; Post: ha afegit v al final de la cua
	Node* nou = new Node;
	nou->v = Videojoc(v);
	nou->seg = NULL;
	if (buida()) {
		a_primer = nou;
		a_darrer = nou;
	}
	else {
		a_darrer->seg = nou;
		a_darrer = nou;
	}
}

void Llista_ord_videojocs::inserir(Videojoc& v) {
	// Pre: --; 
	// Post: si v no existeix s'ha inserit en el lloc que li toca per mantenir l'ordre; en cas contrari es modifica
	Node* ant, * p, * nou;
	bool fiCerca = false;
	bool trobat = false;
	ant = NULL;
	p = a_primer;
	while ((p != NULL) && (!fiCerca)) {
		if (p->v.mateix_nom(v)) {
			trobat = true;
			fiCerca = true;
			p->v.modificar(v);
		}
		else if (p->v >= v) {
			fiCerca = true;
			trobat = p->v == v;
		}
		else {
			ant = p;
			p = p->seg;
		}
	}

	if (!trobat) {
		nou = new Node;
		nou->v = v;
		nou->seg = p;
		if (ant == NULL)
			a_primer = nou;
		else
			ant->seg = nou;
	}
}

void Llista_ord_videojocs::desencua() {
	// Pre: cua no buida; Post: ha eliminat el primer element de la cua
	Node* aux = a_primer;
	if (a_primer == a_darrer) // nomes hi ha un element
		a_primer = a_darrer = NULL;
	else a_primer = a_primer->seg;
	delete aux;
}

void Llista_ord_videojocs::elimina(Videojoc& v) {
	// Pre:--;
	// Post: v s'ha esborrat en el cas que existís; en cas contrari no es fa res
	Node* ant, *p;
	bool trobat = false;
	ant = NULL;
	p = a_primer;
	while ((p != NULL) and (!trobat)) {
		if (p->v == v) {
			trobat = true;
		}
		else {
			ant = p;
			p = p->seg;
		}
		if (trobat) {
			if (ant != NULL)
				ant->seg = p->seg;
			else a_primer = p->seg;
			delete p;
		}
	}
}

void Llista_ord_videojocs::esborra_videojocs_previs_a(Data data) {
	// Pre: cua no buida
	// Post: ha eliminat els elements previs a data de la cua
	Node* p = a_primer;
	while (p != NULL) {
		if (p->v.joc_previ(data)) {
			Node* eliminar = p;
			p = p->seg;
			elimina(eliminar->v);
		}
		else
			p = p->seg;
	}
}

// OPERADORS REDEFINITS 
Llista_ord_videojocs& Llista_ord_videojocs::operator=(const Llista_ord_videojocs& o) {
	// Pre: -- ; Post: aquesta cua es copia de o
	if (this != &o) {
		allibera();
		copia(o);
	}
	return *this;
}

// PRIVATE
void Llista_ord_videojocs::copia(const Llista_ord_videojocs& o) {
	// Pre: memòria dinàmica alliberada; 
	// Post: aquesta llista es còpia de o
	if (!o.buida()) {
		Node* ant, * p, * q;
		p = o.a_primer;
		q = new Node; a_primer = ant = q;
		q->v = p->v; q->seg = NULL;
		p = p->seg;
		while (p != NULL) {
			q = new Node;
			q->v = p->v; q->seg = NULL;
			ant->seg = q;
			ant = q;
			p = p->seg;
		}
	}

}

void Llista_ord_videojocs::allibera() {
	// Pre: --; Post: cua buida
	while (a_primer != NULL) { //!buida()
		Node* aux = a_primer;
		a_primer = a_primer->seg;
		delete aux;
	}
	a_darrer = NULL;
}