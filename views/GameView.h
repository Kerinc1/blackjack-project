#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <string>
#include <vector>
#include "../models/Carta.h" 
#include "../models/Participante.h" 

class GameView {
public:
    // Métodos de utilidad de consola
    static void clearConsole();
    static void waitForKeyPress();

    // Métodos para mostrar menús
    static int showMainMenu(); // Muestra el menú principal y obtiene la elección
    static void showNewRoundHeader(); // Encabezado de nueva ronda

    // Métodos para interacción del jugador
    static bool askForAnotherCard(); // Pregunta si desea otra carta

    // Métodos para mostrar información del juego
    static void displayPlayerHand(const Participante& player); // Muestra la mano de un participante
    static void displayCrupierTurn(); // Mensaje del turno del crupier
    static void displayCrupierDrawsCard(); // Mensaje de que el crupier pide carta

    // Métodos para mostrar resultados
    static void showRoundResultsHeader();
    static void displayFinalScores(int playerScore, int crupierScore);
    static void displayGameOutcome(int playerScore, int crupierScore);
    static void displayRoundEnd();

    // Mensajes generales
    static void displayInvalidOption();
    static void displayPlayerBusted();
    static void displayGoodbye();
};

#endif // GAME_VIEW_H