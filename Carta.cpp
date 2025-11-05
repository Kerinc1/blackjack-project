#include "Carta.h"
#include <iostream>
using namespace std;



// Constructores
Carta::Carta() : nombre(""), valor(0), tipo("") {}

Carta::Carta(const string& nombre, int valor, const string& tipo)
    : nombre(nombre), valor(valor), tipo(tipo) {}

// Métodos getter
string Carta::obtenerNombre() const { return nombre; }
int Carta::obtenerValor() const { return valor; }
string Carta::obtenerTipo() const { return tipo; }

// Métodos setter
void Carta::establecerNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
void Carta::establecerValor(int nuevoValor) { valor = nuevoValor; }
void Carta::establecerTipo(const string& nuevoTipo) { tipo = nuevoTipo; }