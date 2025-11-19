#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Carta.h"

using namespace std;

class Juego {
    private:
        std::vector<Carta> cartas;          // Baraja original
        std::vector<Carta> barajaCartas;    // Baraja barajada
        int siguienteArticulo;              // Índice de la siguiente carta a sacar

        // Métodos privados para crear los palos
        void crearCorazones();
        void crearPicas();
        void crearTrebores();
        void crearDiamantes();

public:
    // Constructor
    Juego();

    // Métodos públicos
    void reiniciarBaraja();
    int obtenerTamañoDeBaraja() const;
    Carta obtenerSiguenteCarta();
    void barajarMazo();
    void mostrarBarajaOriginal() const;
    void mostrarBarajaBarajada() const;
    void MazoCompleto() const;
};

#endif
