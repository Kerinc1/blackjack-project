#include "Crupier.h"

Crupier::Crupier(Juego &juego) : Participante(), juego_(juego) {}

void Crupier::iniciarRonda() {
    juego_.barajarMazo();
    limpiarMano(); // Método heredado de Participante
}

Carta Crupier::sacarCartaDelMazo() {
    return juego_.obtenerSiguenteCarta();
}