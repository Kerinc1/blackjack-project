/*
    Proyecto: Blackjack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos.

    Autor: Jhon Esteban Acosta Gutierrez (2518388)
    Fecha: Octubre 2025
*/

#include <iostream>     
#include <limits>       
#include <string>       
#include <cstdlib>      


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
    // Espera a que el usuario presione Enter
    // Se limpia el buffer primero por si había entradas previas
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// --- Función Principal ---

int main() {

    int choice;



    
    while (true) {
        clearConsole(); 

        cout << "  ____  _            _     _            _    \n";
        cout << " |  _ \\| |          | |   | |          | |   \n";
        cout << " | |_) | | __ _  ___| | __| | __ _  ___| | __\n";
        cout << " |  _ <| |/ _` |/ __| |/ _` |/ _` |/ __| |/ /\n";
        cout << " | |_) | | (_| | (__| | (_| | (_| | (__|   < \n";
        cout << " |____/|_|\\__,_|\\___|_|\\__,_|\\__,_|\\___|_|\\_\\ \n";
        cout << "\n==================================================\n\n";

        cout << "1. Jugar Nueva Ronda\n";
        cout << "2. Salir del Juego\n";
        cout << "Ingrese su elección: ";

        cin >> choice;

        // --- Manejo de entrada no válida (si el usuario escribe "abc") ---
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            choice = 0;  // Asigna una opción no válida para ir al 'default'
        }
        // Descarta cualquier entrada extra en la línea 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // --- Procesar la elección del usuario ---
        switch (choice) {
        case 1:
            // JUGAR NUEVA RONDA
            
            waitForKeyPress(); // Pausa para que el usuario vea los resultados de la ronda
            break;
        case 2:
           
            cout << "Gracias por jugar Blackjack. ¡Vuelve pronto!" << endl;
            return 0; // Termina el programa
        default:
            cout << "Opción no válida. Inténtalo de nuevo.\n";
            waitForKeyPress(); 
            break;
        }
    }
}