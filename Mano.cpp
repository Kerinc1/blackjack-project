#include "Mano.h"
#include <iostream>
using namespace std;

Mano::Mano() : valorTotal(0) {}

void Mano::agregarAMano(const Carta& carta) {
    cartas.push_back(carta);
    valorTotal += carta.obtenerValor();
}

int Mano::obtenerValor() const {
    return valorTotal;
}

void Mano::mostrarMano() const {
    cout << "\n--- Cartas en la mano ---" << endl;
    for (const Carta& carta : cartas) {
        cout << "- " << carta.obtenerNombre()
             << " (" << carta.obtenerTipo()
             << "), valor: " << carta.obtenerValor() << endl;
    }
    cout << "Valor total de la mano: " << valorTotal << endl;
}

void Mano::limpiarMano() {
    cartas.clear();
    valorTotal = 0;
}