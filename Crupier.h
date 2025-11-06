#ifndef CRUPIER_H
#define CRUPIER_H

#include "Carta.h"
#include "Juego.h"

class Crupier {
public:
    explicit Crupier(Juego &juego);
    void EmpezarNuevoJuego();
    Carta obtenerCarta();

private:
    Juego &juego_;
};

#endif // CRUPIER_H
