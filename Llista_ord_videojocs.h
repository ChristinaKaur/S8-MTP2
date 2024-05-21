#ifndef LLISTA_ORD_VIDEOJOCS_H
#define LLISTA_ORD_VIDEOJOCS_H

#include <string>
#include "Videojoc.h"

class Llista_ord_videojocs { // Descripcio: una llista ordenada de videojocs
public:
    // CONSTRUCTORS I DESTRUCTOR 
    Llista_ord_videojocs();
    // Pre: --; Post: cua buida
    Llista_ord_videojocs(const Llista_ord_videojocs& o); 
    // Pre: --; Post: aquesta cua es copia de la Cua o
    ~Llista_ord_videojocs();
    // Pre: --; Post: memoria alliberada
    // COST: O(n)

    // CONSULTORS 
    bool buida() const;
    // Pre: -- ; Post: retorna cert si la cua es buida; fals en c.c.
    Videojoc primer();
    // Pre: cua no buida; 
    // Post: retorna copia del primer string de la cua
    void mostrar() const;
    // Pre: cua no buida; 
    // Post: mostra per pantalla tot el contingut de la cua actual    
    bool existeix(Videojoc& v) const;
    // Pre:--; Post: ens diu si v existeix a la llista
    // 
    // MODIFICADORS 
    void omplir_llista(ifstream& f_in);
    // Pre: fitxer f_in obert correctament
    // Post: llista omplerta amb la informació de f_in
    void encua(Videojoc& v);
    // Pre: --; 
    // Post: ha afegit v al final de la cua
    void inserir(Videojoc& v);
    // Pre: --; 
    // Post: si v no existeix s'ha inserit en el lloc que li toca per mantenir l'ordre; en cas contrari es modifica
    void desencua();
    // Pre: cua no buida; 
    // Post: ha eliminat el primer element de la cua
    void elimina(Videojoc& v);
    // Pre:--;
    // Post: v s'ha esborrat en el cas que existís; en cas contrari no es fa res
    void esborra_videojocs_previs_a(Data data);
    // Pre: cua no buida; Post: ha eliminat els elements previs a data de la cua

    // OPERADORS REDEFINITS 
    Llista_ord_videojocs& operator=(const Llista_ord_videojocs& o);
    // Pre: -- ; Post: aquesta cua es copia de o
    
private:
    struct Node {
        Videojoc v;
        Node* seg;
    };

    // ATRIBUTS
    Node* a_primer; // punter al primer de la cua
    Node* a_darrer; // punter al darrer de la cua
    void copia(const Llista_ord_videojocs& o);
    // Pre: memòria dinàmica alliberada; 
    // Post: aquesta llista es còpia de o
    void allibera();
    // Pre: --; Post: cua buida
};
#endif // LLISTA_ORD_VIDEOJOCS_H