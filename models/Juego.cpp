#include "Juego.h"
#include <iostream>
#include <algorithm>   // std::shuffle
#include <random>      // std::mt19937, std::random_device
using namespace std;

Juego::Juego() {
    reiniciarBaraja();
}

void Juego::reiniciarBaraja() {
    cartas.clear();
    barajaCartas.clear();
    siguienteArticulo = 0;

    crearCorazones();
    crearPicas();
    crearTrebores();
    crearDiamantes();

    barajaCartas = cartas;  // Copiamos la baraja original
}

int Juego::obtenerTamañoDeBaraja() const {
    return static_cast<int>(barajaCartas.size());
}

Carta Juego::obtenerSiguenteCarta() {
    if (siguienteArticulo < static_cast<int>(barajaCartas.size())) {
        return barajaCartas[siguienteArticulo++];
    } else {
        cout << "No quedan cartas en el mazo.\n";
        return Carta(); // Retorna una carta "vacía"
    }
}

void Juego::barajarMazo() {
    random_device rd;
    mt19937 g(rd());
    shuffle(barajaCartas.begin(), barajaCartas.end(), g);
    siguienteArticulo = 0;
}

void Juego::mostrarBarajaOriginal() const {
    cout << "=== Baraja original ===\n";
    for (const auto& carta : cartas) {
        cout << carta.obtenerNombre()
             << " de " << carta.obtenerTipo()
             << " (valor: " << carta.obtenerValor() << ")\n";
    }
}

void Juego::mostrarBarajaBarajada() const {
    cout << "=== Baraja barajada ===\n";
    for (const auto& carta : barajaCartas) {
        cout << carta.obtenerNombre()
             << " de " << carta.obtenerTipo()
             << " (valor: " << carta.obtenerValor() << ")\n";
    }
}

void Juego::MazoCompleto() const {
    cout << "El mazo completo contiene " << cartas.size() << " cartas.\n";
}

void Juego::crearCorazones() {
    for (int valor = 1; valor <= 13; ++valor) {
        string nombre;

        switch (valor) {
            case 1: nombre = "As"; break;
            case 11: nombre = "Jota"; break;
            case 12: nombre = "Reina"; break;
            case 13: nombre = "Rey"; break;
            default: nombre = to_string(valor);
        }

        cartas.push_back(Carta(nombre, valor, "Corazones"));
    }
}

void Juego::crearPicas() {
    for (int valor = 1; valor <= 13; ++valor) {
        string nombre;

        switch (valor) {
            case 1: nombre = "As"; break;
            case 11: nombre = "Jota"; break;
            case 12: nombre = "Reina"; break;
            case 13: nombre = "Rey"; break;
            default: nombre = to_string(valor);
        }

        cartas.push_back(Carta(nombre, valor, "Picas"));
    }
}

void Juego::crearTrebores() {
    for (int valor = 1; valor <= 13; ++valor) {
        string nombre;

        switch (valor) {
            case 1: nombre = "As"; break;
            case 11: nombre = "Jota"; break;
            case 12: nombre = "Reina"; break;
            case 13: nombre = "Rey"; break;
            default: nombre = to_string(valor);
        }

        cartas.push_back(Carta(nombre, valor, "Tréboles"));
    }
}

void Juego::crearDiamantes() {
    for (int valor = 1; valor <= 13; ++valor) {
        string nombre;

        switch (valor) {
            case 1: nombre = "As"; break;
            case 11: nombre = "Jota"; break;
            case 12: nombre = "Reina"; break;
            case 13: nombre = "Rey"; break;
            default: nombre = to_string(valor);
        }

        cartas.push_back(Carta(nombre, valor, "Diamantes"));
    }
}
