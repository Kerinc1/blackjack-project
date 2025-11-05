#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Carta.h"

class Jugador {
private:
    int limite;                  // Límite máximo de valor permitido
    std::vector<Carta> mano;     // Cartas que tiene el jugador

public:
    // Constructor
    Jugador(int limite = 21);    // Por defecto, límite de 21 

    // Métodos públicos
    bool masCartas() const;           
    void obtenerCarta(const Carta& carta);  
    void mostrarMano() const;        
    int obtenerElValorDeLaCarta() const; 
};

#endif
