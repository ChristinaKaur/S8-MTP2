#ifndef VIDEOJOC_H
#define VIDEOJOC_H

#include "Data.h"

#include <string>

using namespace std;

class Videojoc { // Descripcio: un videojoc
public:
    // CONSTRUCTORS
    Videojoc();
    // Pre: --
    // Post: Videojoc inicialitzada
    Videojoc(string nom, int unitats, Data data);
    // Pre: --
    // Post: Videojoc inicialitzada amb dades passades per funcio
    Videojoc(const Videojoc& v);
    // Pre: --
    // Post: Videojoc inicialitzada amb dades de v

    // CONSULTORS
    void mostrar() const;
    // Pre: --
    // Post: mostra per pantalla informacio de del videojoc

    bool joc_previ(const Data& data) const;
    // Pre:--;
    // Post: ens diu si la data de venda del videojoc actual es previa a data  

    bool mateix_nom(Videojoc v) const;
    // Pre:--; 
    // Post: ens diu si el videojoc actual te el mateix nom

    // MODIFICADORS 
    void llegir_videojoc();
    // Pre: --
    // Post: llegir per teclat informacio de del videojoc
    void modificar(const Videojoc v);
    // Pre: --
    // Post: a_data_venda = v.a_data_venda i a_unitats +=v.a_unitats
    
    // OPERADORS REDEFINITS 
    bool operator==(const Videojoc& v) const;
    // Pre: --
    // Post: retorna cert si videojoc actual es igual a v
    bool operator>(const Videojoc& v) const;
    // Pre: --
    // Post: retorna cert si videojoc actual es superior a v

    bool operator>=(const Videojoc& v) const;
    // Pre: --
    // Post: retorna cert si videojoc actual es superior o igual a v

    void operator=(const Videojoc& v);
    // Pre: --
    // Post: videojoc actual = v

    friend ostream& operator<<(ostream& o, const Videojoc& v);
    // Pre: es pot escriure a o; 
    // Post: s’ha escrit la informació de v a o

    friend istream& operator>>(istream& i, Videojoc& v);
    // Pre: es pot llegir d’i; 
    // Post: v conté les dades llegides d’i

private:
    string a_nom;
    int a_unitats;
    Data a_data_venda;
};
#endif // VIDEOJOC_H