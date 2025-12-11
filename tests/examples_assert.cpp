#include <iostream>
#include <cassert>
#include "../models/Carta.h"
#include "../models/Mano.h"
#include "../models/Participante.h"
#include "../models/Jugador.h"
#include "../models/Juego.h"
#include "../models/Crupier.h"

using namespace std;

/**
 * EJEMPLOS DE USO DE PRUEBAS UNITARIAS CON ASSERT
 * 
 * Este archivo demuestra cómo usar asserts para validar el funcionamiento
 * de las clases del proyecto Blackjack sin depender de un framework de pruebas.
 */

void pruebasCarta() {
    cout << "=== Pruebas de Carta ===" << endl;
    
    // Prueba 1: Constructor por defecto
    Carta c1;
    assert(c1.obtenerNombre() == "");
    assert(c1.obtenerValor() == 0);
    cout << "✓ Constructor por defecto funciona" << endl;
    
    // Prueba 2: Constructor con parámetros
    Carta c2("Rey", 13, "Picas");
    assert(c2.obtenerNombre() == "Rey");
    assert(c2.obtenerValor() == 13);
    assert(c2.obtenerTipo() == "Picas");
    cout << "✓ Constructor con parámetros funciona" << endl;
    
    // Prueba 3: Setters
    Carta c3;
    c3.establecerNombre("As");
    c3.establecerValor(1);
    c3.establecerTipo("Corazones");
    assert(c3.obtenerNombre() == "As");
    assert(c3.obtenerValor() == 1);
    assert(c3.obtenerTipo() == "Corazones");
    cout << "✓ Setters funcionan correctamente" << endl;
    
    cout << endl;
}

void pruebasMano() {
    cout << "=== Pruebas de Mano ===" << endl;
    
    // Prueba 1: Mano vacía
    Mano m1;
    assert(m1.calcularValor() == 0);
    cout << "✓ Mano vacía tiene valor 0" << endl;
    
    // Prueba 2: Agregar cartas numéricas
    Mano m2;
    m2.agregarAMano(Carta("5", 5, "Corazones"));
    m2.agregarAMano(Carta("10", 10, "Picas"));
    assert(m2.calcularValor() == 15);
    cout << "✓ Suma de cartas numéricas correcta (5 + 10 = 15)" << endl;
    
    // Prueba 3: Figuras valen 10
    Mano m3;
    m3.agregarAMano(Carta("Rey", 13, "Corazones"));
    assert(m3.calcularValor() == 10);
    cout << "✓ Figuras se cuentan como 10" << endl;
    
    // Prueba 4: Lógica de Ases
    Mano m4;
    m4.agregarAMano(Carta("As", 1, "Corazones"));
    m4.agregarAMano(Carta("5", 5, "Picas"));
    assert(m4.calcularValor() == 16); // As como 11 + 5
    cout << "✓ As se cuenta como 11 cuando no hay bust (11 + 5 = 16)" << endl;
    
    // Prueba 5: As como 1 para evitar bust
    Mano m5;
    m5.agregarAMano(Carta("As", 1, "Corazones"));
    m5.agregarAMano(Carta("10", 10, "Picas"));
    m5.agregarAMano(Carta("5", 5, "Diamantes"));
    assert(m5.calcularValor() == 16); // As como 1 + 10 + 5
    cout << "✓ As se cuenta como 1 para evitar bust (1 + 10 + 5 = 16)" << endl;
    
    // Prueba 6: Blackjack
    Mano m6;
    m6.agregarAMano(Carta("As", 1, "Corazones"));
    m6.agregarAMano(Carta("Rey", 13, "Picas"));
    assert(m6.calcularValor() == 21);
    cout << "✓ Blackjack: As + Rey = 21" << endl;
    
    // Prueba 7: Limpiar mano
    m6.limpiarMano();
    assert(m6.calcularValor() == 0);
    cout << "✓ Limpiar mano funciona correctamente" << endl;
    
    cout << endl;
}

void pruebasParticipante() {
    cout << "=== Pruebas de Participante ===" << endl;
    
    // Prueba 1: Participante vacío
    Participante p1;
    assert(p1.obtenerPuntaje() == 0);
    cout << "✓ Participante inicial tiene puntaje 0" << endl;
    
    // Prueba 2: Recibir cartas
    Participante p2;
    p2.recibirCarta(Carta("7", 7, "Corazones"));
    assert(p2.obtenerPuntaje() == 7);
    cout << "✓ Participante puede recibir cartas" << endl;
    
    // Prueba 3: Puntaje con múltiples cartas
    Participante p3;
    p3.recibirCarta(Carta("10", 10, "Corazones"));
    p3.recibirCarta(Carta("5", 5, "Picas"));
    assert(p3.obtenerPuntaje() == 15);
    cout << "✓ Puntaje se acumula correctamente" << endl;
    
    // Prueba 4: Limpiar mano
    p3.limpiarMano();
    assert(p3.obtenerPuntaje() == 0);
    cout << "✓ Limpiar mano restaura puntaje a 0" << endl;
    
    cout << endl;
}

void pruebasJugador() {
    cout << "=== Pruebas de Jugador ===" << endl;
    
    // Prueba 1: Jugador quiere más cartas si puntaje < 21
    Jugador j1(21);
    j1.recibirCarta(Carta("5", 5, "Corazones"));
    assert(j1.quiereMasCartas() == true);
    cout << "✓ Jugador quiere más cartas cuando puntaje < límite" << endl;
    
    // Prueba 2: Jugador no quiere más cartas si puntaje >= 21
    Jugador j2(21);
    j2.recibirCarta(Carta("10", 10, "Corazones"));
    j2.recibirCarta(Carta("10", 10, "Picas"));
    j2.recibirCarta(Carta("1", 1, "Diamantes"));
    assert(j2.quiereMasCartas() == false);
    cout << "✓ Jugador no quiere más cartas cuando puntaje >= límite" << endl;
    
    // Prueba 3: Límite personalizado
    Jugador j3(15);
    j3.recibirCarta(Carta("10", 10, "Corazones"));
    assert(j3.quiereMasCartas() == true); // 10 < 15
    j3.recibirCarta(Carta("5", 5, "Picas"));
    assert(j3.quiereMasCartas() == false); // 15 no es < 15
    cout << "✓ Límite personalizado funciona correctamente" << endl;
    
    cout << endl;
}

void pruebasJuego() {
    cout << "=== Pruebas de Juego ===" << endl;
    
    // Prueba 1: Juego tiene 52 cartas
    Juego g1;
    assert(g1.obtenerTamañoDeBaraja() == 52);
    cout << "✓ Juego inicializa con 52 cartas" << endl;
    
    // Prueba 2: Obtener cartas
    Juego g2;
    Carta c = g2.obtenerSiguenteCarta();
    assert(c.obtenerNombre() != "");
    cout << "✓ Se puede obtener la siguiente carta" << endl;
    
    // Prueba 3: Barajar y reiniciar
    Juego g3;
    g3.obtenerSiguenteCarta();
    g3.barajarMazo();
    assert(g3.obtenerTamañoDeBaraja() == 52);
    cout << "✓ Barajar restablece la posición correctamente" << endl;
    
    // Prueba 4: Reiniciar baraja
    Juego g4;
    for (int i = 0; i < 52; i++) {
        g4.obtenerSiguenteCarta();
    }
    g4.reiniciarBaraja();
    assert(g4.obtenerTamañoDeBaraja() == 52);
    cout << "✓ Reiniciar baraja funciona correctamente" << endl;
    
    cout << endl;
}

void pruebasCrupier() {
    cout << "=== Pruebas de Crupier ===" << endl;
    
    // Prueba 1: Crupier inicializado
    Juego g;
    Crupier c(g);
    assert(c.obtenerPuntaje() == 0);
    cout << "✓ Crupier se inicializa con puntaje 0" << endl;
    
    // Prueba 2: Iniciar ronda limpia la mano
    Crupier c2(g);
    c2.recibirCarta(Carta("10", 10, "Corazones"));
    c2.recibirCarta(Carta("10", 10, "Picas"));
    c2.iniciarRonda();
    assert(c2.obtenerPuntaje() == 0);
    cout << "✓ Iniciar ronda limpia la mano del crupier" << endl;
    
    // Prueba 3: Sacar cartas del mazo
    Juego g3;
    Crupier c3(g3);
    c3.iniciarRonda();
    Carta cartaCrupier = c3.sacarCartaDelMazo();
    assert(cartaCrupier.obtenerNombre() != "");
    cout << "✓ Crupier puede sacar cartas del mazo" << endl;
    
    cout << endl;
}

int main() {
    cout << "╔════════════════════════════════════════════════╗" << endl;
    cout << "║  EJEMPLOS DE PRUEBAS CON ASSERT - BLACKJACK  ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    try {
        pruebasCarta();
        pruebasMano();
        pruebasParticipante();
        pruebasJugador();
        pruebasJuego();
        pruebasCrupier();
        
        cout << "╔════════════════════════════════════════════════╗" << endl;
        cout << "║         ✓ TODAS LAS PRUEBAS PASARON            ║" << endl;
        cout << "║                                                ║" << endl;
        cout << "║  Total de asserts ejecutados: ~35              ║" << endl;
        cout << "║  Tasa de éxito: 100%                           ║" << endl;
        cout << "╚════════════════════════════════════════════════╝" << endl;
        
        return 0;
    } catch (const exception& e) {
        cerr << "✗ Error en pruebas: " << e.what() << endl;
        return 1;
    }
}
