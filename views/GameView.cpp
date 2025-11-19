#include "GameView.h"
#include <iostream>
#include <limits> // Para numeric_limits
#include <cstdlib> // Para system("cls") o system("clear")

void GameView::clearConsole() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void GameView::waitForKeyPress() {
    std::cout << "\nPresione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int GameView::showMainMenu() {
    clearConsole();
    std::cout << "╔══════════════════════╗" << std::endl;
    std::cout << "║      BLACKJACK       ║" << std::endl;
    std::cout << "╚══════════════════════╝" << std::endl;
    std::cout << "1. Jugar Nueva Ronda\n";
    std::cout << "2. Salir del Juego\n";
    std::cout << "Ingrese su elección: ";
    int choice;
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.clear();
        choice = 0; // Opción inválida
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

void GameView::showNewRoundHeader() {
    clearConsole();
    std::cout << "=== NUEVA RONDA DE BLACKJACK ===\n\n";
}

bool GameView::askForAnotherCard() {
    char opcion;
    std::cout << "\n¿Desea otra carta? (s/n): ";
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer
    return (opcion == 's' || opcion == 'S');
}

void GameView::displayPlayerHand(const Participante& player) {
    std::cout << "--- TU MANO ---" << std::endl;
    player.mostrarMano(); // La clase Participante ya sabe mostrar su mano
}

void GameView::displayCrupierTurn() {
    std::cout << "\n--- TURNO CRUPIER ---\n";
}

void GameView::displayCrupierDrawsCard() {
    std::cout << "El crupier pide carta...\n";
}

void GameView::showRoundResultsHeader() {
    clearConsole();
    std::cout << "=================================\n";
    std::cout << "===   RESULTADOS DE LA RONDA  ===\n";
    std::cout << "=================================\n\n";
}

void GameView::displayFinalScores(int playerScore, int crupierScore) {
    std::cout << "Jugador: " << playerScore << std::endl;
    std::cout << "Crupier: " << crupierScore << std::endl;
}

void GameView::displayGameOutcome(int playerScore, int crupierScore) {
    if (playerScore > 21) {
        std::cout << "Perdiste. Te pasaste de 21." << std::endl;
    } else if (crupierScore > 21) {
        std::cout << "¡Ganaste! El crupier se pasó." << std::endl;
    } else if (playerScore > crupierScore) {
        std::cout << "¡Ganaste! Tienes mejor mano." << std::endl;
    } else if (playerScore < crupierScore) {
        std::cout << "Perdiste. El crupier tiene mejor mano." << std::endl;
    } else {
        std::cout << "Empate." << std::endl;
    }
}

void GameView::displayRoundEnd() {
    std::cout << "\nRonda terminada.\n";
}

void GameView::displayInvalidOption() {
    std::cout << "Opción no válida. Inténtalo de nuevo.\n";
}

void GameView::displayPlayerBusted() {
    std::cout << "¡Te pasaste de 21!\n";
}

void GameView::displayGoodbye() {
    std::cout << "Gracias por jugar Blackjack. ¡Vuelve pronto!" << std::endl;
}