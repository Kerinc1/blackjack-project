/*
    Clase: Carta

    Responsabilidades:
        - Representar una sola carta del mazo de blackjack.
        - Almacenar y administrar la información de la carta: su nombre, valor numérico y tipo (palo o categoría).
        - Proveer métodos públicos para obtener y establecer los valores de sus atributos.

    Colaboradores:
        - Colabora con la clase `Mano`, que utiliza objetos `Carta` para conformar
          la mano de un jugador o del crupier.
        - Colabora indirectamente con la clase `Juego`, que genera y gestiona
          las cartas a través de la baraja.
*/
#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta {
private:
    string nombre;
    int valor;
    string tipo;

public:
    Carta();
    Carta(const string& nombre, int valor, const string& tipo);

    string obtenerNombre() const;
    int obtenerValor() const;
    string obtenerTipo() const;

    void establecerNombre(const string& nombre);
    void establecerValor(int valor);
    void establecerTipo(const string& tipo);
};

#endif

