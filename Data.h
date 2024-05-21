#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class Data { // Descripcio: una data
public:
    // CONSTRUCTORS
    Data();
    // Pre: cert; Post: és la data 1/1/2001
    Data(int d, int m, int a);
    // Pre: cert; Post: és la data d/m/a si és correcta o 1/1/2001 en cas contrari

    // CONSULTORS
    void mostrar(int format) const;
    // Pre: format 1 o 2;
    // Post: mostra la data actual en format d/m/a o dmesa

    // MODIFICADORS
    void llegir(int format);
    // Pre: format 1 o 2;
    // Post: llegeix dates en format AAAAMMDD o d m a, fins a llegir-ne una de correcta
    bool operator ==(const Data& d) const;
    // Pre: cert
    // Post: cert si d és igual a la data actual, fals altrament
    bool operator !=(const Data& d) const;
    // Pre: cert
    // Post: cert si d no és igual a la data actual, fals altrament
    bool operator <(const Data& d) const;
    // Pre: cert
    // Post: cert si d és una data posterior a l'actual, fals altrament
    bool operator >(const Data& d) const;
    // Pre: cert
    // Post: cert si data actual és una data posterior a d, fals altrament
    bool operator <=(const Data& d) const;
    // Pre: cert
    // Post: cert si d és una data posterior o igual a l'actual, fals altrament
    bool operator >=(const Data& d) const;
    // Pre: cert
    // Post: cert si data actual és una data posterior o igual a d, fals altrament

    friend ostream& operator<<(ostream& o, const Data& d);
    // Pre: es pot escriure a o; 
    // Post: s’ha escrit la informació de d a o

    friend istream& operator>>(istream& i, Data& d);
    // Pre: es pot llegir d’i; 
    // Post: d conté les dades llegides d’i

private:
    int a_dia;
    int a_mes;
    int a_any;
    // CONSTANTS DE CLASSE
    static const int MESOS_ANY = 12;
    static const int DIES_MES[];
    static const string NOM_MES[];
    // FUNCIONS DE CLASSE
    static bool es_data_valida(int dia, int mes, int any);
    // Pre: cert;
    // Post: cert si dia/mes/any seria una data vàlida en el calendari gregorià (entre anys 1600 i 4000), fals altrament
};
#endif // DATA_H