#include "Participante.h"

Participante::Participante() {}

Participante::~Participante() {}

void Participante::recibirCarta(const Carta& carta) {
    mano.agregarAMano(carta);
}

int Participante::obtenerPuntaje() const {
    return mano.calcularValor();
}

void Participante::mostrarMano() const {
    mano.mostrarMano();
}

void Participante::limpiarMano() {
    mano.limpiarMano();
}