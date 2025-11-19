#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int limite) : Participante(), limite(limite) {}

bool Jugador::quiereMasCartas() const {
    // Usa el método heredado obtenerPuntaje()
    return obtenerPuntaje() < limite;
}