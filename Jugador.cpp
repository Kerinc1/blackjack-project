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
    int numAces = 0; 

    // Sumar todas las cartas con su valor de Blackjack
    for (const auto& carta : mano) {
        int valor = carta.obtenerValor(); // Obtenemos el valor (1=As, 11=J, 12=Q, 13=K)

        if (valor == 1) { // Es un As
            numAces++;
            total += 1; // Lo contamos como 1... por ahora
        } 
        else if (valor > 10) { // Es J, Q, o K
            total += 10; // Valen 10
        } 
        else { // Es una carta 2-10
            total += valor; // Vale su propio número
        }
    }

    // Lógica especial para los Ases
    // Si tenemos Ases y el puntaje es bajo, intentamos
    // convertir un As de 1 a 11 (sumando 10 extra).
    while (numAces > 0 && (total + 10) <= 21) {
        total += 10; // Se convierte un As de 1 a 11
        numAces--;   // Ya "usamos" ese As para valer 11
    }

    // Devuelve el puntaje final
    return total;
}
