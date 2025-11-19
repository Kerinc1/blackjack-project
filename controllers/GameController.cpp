#include "GameController.h"
#include <iostream>

GameController::GameController() 
    : game(), player(21), crupier(game) // Inicializa el juego, jugador y crupier
{}

void GameController::runGameLoop() {
    while (true) {
        int choice = GameView::showMainMenu(); // Usa la vista para mostrar menú y obtener elección

        switch (choice) {
            case 1:
                playRound(); // Jugar una ronda
                GameView::waitForKeyPress();
                break;
            case 2:
                GameView::displayGoodbye();
                return; // Salir del bucle y del juego
            default:
                GameView::displayInvalidOption();
                GameView::waitForKeyPress();
                break;
        }
    }
}

void GameController::playRound() {
    GameView::showNewRoundHeader();

    // Resetear y barajar
    crupier.iniciarRonda(); // Inicia la ronda, limpia manos y baraja
    player.limpiarMano();

    // Repartir cartas iniciales
    player.recibirCarta(crupier.sacarCartaDelMazo());
    player.recibirCarta(crupier.sacarCartaDelMazo());
    crupier.recibirCarta(crupier.sacarCartaDelMazo());
    crupier.recibirCarta(crupier.sacarCartaDelMazo());

    // Turno del Jugador
    GameView::displayPlayerHand(player);
    while (player.quiereMasCartas() && GameView::askForAnotherCard()) {
        player.recibirCarta(crupier.sacarCartaDelMazo());
        GameView::displayPlayerHand(player);
        if (player.obtenerPuntaje() > 21) {
            GameView::displayPlayerBusted();
            break;
        }
    }

    // Turno del Crupier (solo si el jugador no se ha pasado)
    if (player.obtenerPuntaje() <= 21) {
        GameView::displayCrupierTurn();
        // Mostrar solo la primera carta del crupier inicialmente, luego el resto
        // Esto sería una mejora de la vista, por ahora mostramos todo.
        crupier.mostrarMano(); // Muestra la mano completa del crupier
        while (crupier.obtenerPuntaje() < 17) {
            GameView::displayCrupierDrawsCard();
            crupier.recibirCarta(crupier.sacarCartaDelMazo());
            crupier.mostrarMano();
        }
    }

    // Mostrar Resultados
    GameView::showRoundResultsHeader();
    int ptjJugador = player.obtenerPuntaje();
    int ptjCrupier = crupier.obtenerPuntaje();
    GameView::displayFinalScores(ptjJugador, ptjCrupier);
    GameView::displayGameOutcome(ptjJugador, ptjCrupier);
    GameView::displayRoundEnd();
}