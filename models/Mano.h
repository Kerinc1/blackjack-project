#ifndef MANO_H
#define MANO_H

#include <vector>
#include "Carta.h"

class Mano {
private:
    std::vector<Carta> cartas;

public:
    Mano();
    void agregarAMano(const Carta& carta);
    int calcularValor() const; // Cambiamos nombre a calcularValor para ser más claros
    void mostrarMano() const;
    void limpiarMano();
};

#endif