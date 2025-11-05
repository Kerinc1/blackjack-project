#ifndef MANO_H
#define MANO_H

#include <vector>
#include "Carta.h"
using namespace std;

class Mano {
private:
    vector<Carta> cartas;
    int valorTotal;

public:
    Mano();

    void agregarAMano(const Carta& carta);
    int obtenerValor() const;
    void mostrarMano() const;
    void limpiarMano();
};

#endif

