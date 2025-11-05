#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta {
private:
    string nombre;
    int valor;
    string tipo;

public:
    Carta();
    Carta(const string& nombre, int valor, const string& tipo);

    string obtenerNombre() const;
    int obtenerValor() const;
    string obtenerTipo() const;

    void establecerNombre(const string& nombre);
    void establecerValor(int valor);
    void establecerTipo(const string& tipo);
};

#endif

