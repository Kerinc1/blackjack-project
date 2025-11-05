/*
    Clase: Mano

    Responsabilidades:
        - Representar la colección de cartas que posee un jugador o el crupier.
        - Gestionar las cartas agregadas a la mano durante el juego.
        - Calcular y devolver el valor total de la mano según las reglas del blackjack.
        - Mostrar las cartas que contiene la mano.

    Colaboradores:
        - Colabora con la clase `Carta`, ya que cada mano está compuesta por
          múltiples objetos de tipo `Carta`.
        - Colabora con las clases `Jugador` y `Crupier`, que poseen una instancia
          de `Mano` para administrar sus cartas.
*/
#ifndef MANO_H
#define MANO_H

#include <vector>
#include "Carta.h"
using namespace std;

class Mano {
private:
    vector<Carta> cartas;
    int valorTotal;

public:
    Mano();

    void agregarAMano(const Carta& carta);
    int obtenerValor() const;
    void mostrarMano() const;
    void limpiarMano();
};

#endif

