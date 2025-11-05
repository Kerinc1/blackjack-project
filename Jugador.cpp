#include "Jugador.h"
#include <iostream>
using namespace std;

// Constructor
Jugador::Jugador(int limite) : limite(limite) {}

// Devuelve true si el jugador puede seguir pidiendo cartas
bool Jugador::masCartas() const {
    return obtenerElValorDeLaCarta() < limite;
}

// Agrega una carta a la mano del jugador
void Jugador::obtenerCarta(const Carta& carta) {
    mano.push_back(carta);
}

// Muestra las cartas actuales del jugador
void Jugador::mostrarMano() const {
    cout << "Cartas del jugador:\n";
    for (const auto& carta : mano) {
        cout << "- " << carta.obtenerNombre()
             << " de " << carta.obtenerTipo()
             << " (valor: " << carta.obtenerValor() << ")\n";
    }
    cout << "Valor total: " << obtenerElValorDeLaCarta() << endl;
}

// Devuelve la suma de los valores de las cartas del jugador
int Jugador::obtenerElValorDeLaCarta() const {
    int total = 0;
    for (const auto& carta : mano) {
        total += carta.obtenerValor();
    }
    return total;
}
