#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../models/Juego.h"
#include "../models/Jugador.h"
#include "../models/Crupier.h"
#include "../views/GameView.h" 

class GameController {
private:
    Juego game;
    Jugador player;
    Crupier crupier;

public:
    GameController();
    void runGameLoop(); // El bucle principal del juego
    void playRound();   // Lógica de una sola ronda
};

#endif // GAME_CONTROLLER_H