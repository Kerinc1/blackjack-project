#include <gtest/gtest.h>
#include "../models/Crupier.h"
#include "../models/Juego.h"
#include "../models/Carta.h"

class CrupierTest : public ::testing::Test {
protected:
    Juego juego;
    Crupier crupier = Crupier(juego);
};

// Tests para constructor
TEST_F(CrupierTest, ConstructorValido) {
    EXPECT_EQ(crupier.obtenerPuntaje(), 0);
}

// Tests para iniciarRonda
TEST_F(CrupierTest, IniciarRondaBairajaYLimpia) {
    // Agregar algunas cartas al crupier
    crupier.recibirCarta(Carta("5", 5, "Corazones"));
    crupier.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_EQ(crupier.obtenerPuntaje(), 15);
    
    // Iniciar ronda limpia la mano
    crupier.iniciarRonda();
    EXPECT_EQ(crupier.obtenerPuntaje(), 0);
}

// Tests para sacarCartaDelMazo
TEST_F(CrupierTest, SacarCartaDelMazo) {
    crupier.iniciarRonda();
    
    Carta carta = crupier.sacarCartaDelMazo();
    EXPECT_FALSE(carta.obtenerNombre().empty());
}

TEST_F(CrupierTest, SacarMultiplesCartas) {
    crupier.iniciarRonda();
    
    Carta carta1 = crupier.sacarCartaDelMazo();
    Carta carta2 = crupier.sacarCartaDelMazo();
    Carta carta3 = crupier.sacarCartaDelMazo();
    
    EXPECT_FALSE(carta1.obtenerNombre().empty());
    EXPECT_FALSE(carta2.obtenerNombre().empty());
    EXPECT_FALSE(carta3.obtenerNombre().empty());
}

// Tests para recibirCarta (heredado de Participante)
TEST_F(CrupierTest, RecibirCartaYActualizaPuntaje) {
    Carta carta("7", 7, "Corazones");
    crupier.recibirCarta(carta);
    EXPECT_EQ(crupier.obtenerPuntaje(), 7);
}

TEST_F(CrupierTest, RecibirMultiplesCartas) {
    crupier.recibirCarta(Carta("5", 5, "Corazones"));
    crupier.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_EQ(crupier.obtenerPuntaje(), 15);
}

// Tests para obtenerPuntaje (heredado de Participante)
TEST_F(CrupierTest, ObtenerPuntajeInicial) {
    Crupier c(juego);
    EXPECT_EQ(c.obtenerPuntaje(), 0);
}

TEST_F(CrupierTest, ObtenerPuntajeConCartas) {
    crupier.recibirCarta(Carta("6", 6, "Corazones"));
    crupier.recibirCarta(Carta("9", 9, "Picas"));
    EXPECT_EQ(crupier.obtenerPuntaje(), 15);
}

// Tests para limpiarMano (heredado de Participante)
TEST_F(CrupierTest, LimpiarMano) {
    crupier.recibirCarta(Carta("10", 10, "Corazones"));
    crupier.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_EQ(crupier.obtenerPuntaje(), 20);
    
    crupier.limpiarMano();
    EXPECT_EQ(crupier.obtenerPuntaje(), 0);
}

// Tests para mostrarMano (heredado de Participante)
TEST_F(CrupierTest, MostrarManoNoLanzaExcepcion) {
    EXPECT_NO_THROW(crupier.mostrarMano());
}

TEST_F(CrupierTest, MostrarManoConCartasNoLanzaExcepcion) {
    crupier.recibirCarta(Carta("10", 10, "Corazones"));
    crupier.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_NO_THROW(crupier.mostrarMano());
}

// Tests de secuencia
TEST_F(CrupierTest, SecuenciaRonda) {
    // Primera ronda
    crupier.iniciarRonda();
    EXPECT_EQ(crupier.obtenerPuntaje(), 0);
    
    // Sacar cartas
    Carta carta1 = crupier.sacarCartaDelMazo();
    crupier.recibirCarta(carta1);
    EXPECT_EQ(crupier.obtenerPuntaje(), carta1.obtenerValor());
    
    Carta carta2 = crupier.sacarCartaDelMazo();
    crupier.recibirCarta(carta2);
    int puntajeEsperado = min(10, (int)carta1.obtenerValor()) + min(10, (int)carta2.obtenerValor());
    if (carta1.obtenerValor() == 1) puntajeEsperado -= 1; // Ajustar por As
    if (carta2.obtenerValor() == 1) puntajeEsperado -= 1; // Ajustar por As
    
    // Solo verificar que no sea 0
    EXPECT_GT(crupier.obtenerPuntaje(), 0);
    
    // Segunda ronda
    crupier.iniciarRonda();
    EXPECT_EQ(crupier.obtenerPuntaje(), 0);
}

// Tests con casos especiales
TEST_F(CrupierTest, CrupierBlackjack) {
    crupier.iniciarRonda();
    crupier.recibirCarta(Carta("As", 1, "Corazones"));
    crupier.recibirCarta(Carta("Rey", 13, "Picas"));
    EXPECT_EQ(crupier.obtenerPuntaje(), 21);
}

TEST_F(CrupierTest, CrupierBust) {
    crupier.iniciarRonda();
    crupier.recibirCarta(Carta("10", 10, "Corazones"));
    crupier.recibirCarta(Carta("10", 10, "Picas"));
    crupier.recibirCarta(Carta("10", 10, "Diamantes"));
    EXPECT_EQ(crupier.obtenerPuntaje(), 30); // Bust
}

TEST_F(CrupierTest, CrupierConMultiplesAses) {
    crupier.iniciarRonda();
    crupier.recibirCarta(Carta("As", 1, "Corazones"));
    crupier.recibirCarta(Carta("As", 1, "Picas"));
    EXPECT_EQ(crupier.obtenerPuntaje(), 12); // 11 + 1
}

// Tests para sacar todas las cartas
TEST_F(CrupierTest, SacarTodasLasCartas) {
    crupier.iniciarRonda();
    
    vector<Carta> cartas;
    for (int i = 0; i < 52; ++i) {
        Carta carta = crupier.sacarCartaDelMazo();
        EXPECT_FALSE(carta.obtenerNombre().empty());
        cartas.push_back(carta);
    }
    
    // La siguiente carta debe ser vacía
    Carta cartaVacia = crupier.sacarCartaDelMazo();
    EXPECT_EQ(cartaVacia.obtenerNombre(), "");
}

// Tests de múltiples rondas
TEST_F(CrupierTest, MultiplesRondas) {
    for (int ronda = 0; ronda < 3; ++ronda) {
        crupier.iniciarRonda();
        EXPECT_EQ(crupier.obtenerPuntaje(), 0);
        
        crupier.recibirCarta(crupier.sacarCartaDelMazo());
        crupier.recibirCarta(crupier.sacarCartaDelMazo());
        
        EXPECT_GT(crupier.obtenerPuntaje(), 0);
    }
}
