#include "Crupier.h"

Crupier::Crupier(Juego &juego)
    : juego_(juego)
{
}

void Crupier::EmpezarNuevoJuego()
{
    juego_.barajarMazo();
}

Carta Crupier::obtenerCarta()
{
    return juego_.obtenerSiguenteCarta();
}
