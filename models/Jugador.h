#ifndef JUGADOR_H
#define JUGADOR_H

#include "Participante.h" // Hereda de participante

class Jugador : public Participante {
private:
    int limite;

public:
    Jugador(int limite = 21);
    
    bool quiereMasCartas() const; 
};

#endif