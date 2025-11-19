#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include "Mano.h"
#include "Carta.h"

class Participante {
protected:
    Mano mano; // El atributo compartido

public:
    Participante();
    virtual ~Participante(); // Destructor virtual por seguridad

    // Métodos que heredan todos
    virtual void recibirCarta(const Carta& carta);
    virtual int obtenerPuntaje() const;
    virtual void mostrarMano() const;
    virtual void limpiarMano();
};

#endif