/*
    Proyecto: Blackjack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos.

    Autor: Jhon Esteban Acosta Gutierrez - 2518388
           Benjamin Lopera Ochoa - 2515144-2724
           Jhonny Alexander Moreno Florez - 2522112

    Fecha: Octubre/noviembre 2025
*/

#include <iostream>     
#include <limits>       
#include <string>       
#include <cstdlib>  
#include "Carta.h"
#include "Mano.h"    

#include "Juego.h"
#include "Jugador.h"

using namespace std;

void clearConsole() {
    #ifdef _WIN32
    system("cls"); // Comando para Windows
    #else
    system("clear"); // Comando para Linux/Mac
    #endif
}

void waitForKeyPress() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// --- Función Principal ---
int main() {
    int choice;

    while (true) {
        clearConsole();

        cout << "╔══════════════════════╗" << std::endl;
        cout << "║      BLACKJACK       ║" << std::endl;
        cout << "╚══════════════════════╝" << std::endl;

        cout << "1. Jugar Nueva Ronda\n";
        cout << "2. Salir del Juego\n";
        cout << "Ingrese su elección: ";

        cin >> choice;

        // Manejo de entrada no válida
        if (cin.fail()) {
            cin.clear();
            choice = 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            // === JUGAR NUEVA RONDA ===
            clearConsole();
            cout << "=== NUEVA RONDA DE BLACKJACK ===\n\n";

            // Crear el juego y el jugador
            Juego juego;
            Jugador jugador(21);

            // Barajar el mazo antes de repartir
            juego.barajarMazo();

            // Dar 2 cartas iniciales al jugador
            jugador.obtenerCarta(juego.obtenerSiguenteCarta());
            jugador.obtenerCarta(juego.obtenerSiguenteCarta());

            // Mostrar mano inicial
            jugador.mostrarMano();

            // Lógica simple de pedir más cartas
            while (jugador.masCartas()) {
                char opcion;
                cout << "\n¿Desea otra carta? (s/n): ";
                cin >> opcion;

                if (opcion == 's' || opcion == 'S') {
                    jugador.obtenerCarta(juego.obtenerSiguenteCarta());
                    jugador.mostrarMano();
                } else {
                    break;
                }
            }

            cout << "\nRonda terminada.\n";
            waitForKeyPress();
            break;
        }

        case 2:
            cout << "Gracias por jugar Blackjack. ¡Vuelve pronto!" << endl;
            return 0;

        default:
            cout << "Opción no válida. Inténtalo de nuevo.\n";
            waitForKeyPress();
            break;
        }
    }
}
