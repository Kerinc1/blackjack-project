#ifndef CRUPIER_H
#define CRUPIER_H

#include "Participante.h"
#include "Juego.h"

class Crupier : public Participante {
private:
    Juego &juego_; // Referencia al juego para sacar cartas

public:
    explicit Crupier(Juego &juego);
    
    void iniciarRonda();
    Carta sacarCartaDelMazo(); // Renombrado para no confundir con recibirCarta
};

#endif