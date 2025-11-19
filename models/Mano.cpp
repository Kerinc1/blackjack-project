#include "Mano.h"
#include <iostream>
using namespace std;

Mano::Mano() {}

void Mano::agregarAMano(const Carta& carta) {
    cartas.push_back(carta);
}

int Mano::calcularValor() const {
    int total = 0;
    int numAces = 0;

    for (const auto& carta : cartas) {
        int valor = carta.obtenerValor(); 
        if (valor == 1) { // Es un As
            numAces++;
            total += 1; 
        } else if (valor > 10) { // J, Q, K
            total += 10;
        } else {
            total += valor;
        }
    }

    // Lógica de Ases (convertir 1 a 11 si conviene)
    while (numAces > 0 && (total + 10) <= 21) {
        total += 10;
        numAces--;
    }
    return total;
}

void Mano::mostrarMano() const {
    cout << "--- Cartas en mano ---" << endl;
    for (const auto& carta : cartas) {
        cout << "- " << carta.obtenerNombre() 
             << " (" << carta.obtenerTipo() << ")"
             << " Val: " << carta.obtenerValor() << endl;
    }
    cout << "Puntaje Total: " << calcularValor() << endl;
}

void Mano::limpiarMano() {
    cartas.clear();
}