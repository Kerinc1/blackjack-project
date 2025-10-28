/*
    Clase: Jugador

    Responsabilidades:
        - 
        -
        - 

    Colaboradores:
        - 
        - 
*/

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
    Jugador(int limite = 21);    // Por defecto, límite de 21 (similar al blackjack)

    // Métodos públicos
    bool masCartas() const;           // ¿El jugador puede pedir más cartas?
    void obtenerCarta(const Carta& carta);  // Agrega una carta a la mano
    void mostrarMano() const;         // Muestra todas las cartas del jugador
    int obtenerElValorDeLaCarta() const; // Suma total de los valores de las cartas
};

#endif
