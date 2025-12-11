#include <gtest/gtest.h>
#include "../models/Jugador.h"
#include "../models/Carta.h"

class JugadorTest : public ::testing::Test {
protected:
    Jugador jugador;
    Jugador jugadorLimite15;

    void SetUp() override {
        // Constructor por defecto crea jugador con límite 21
        jugadorLimite15 = Jugador(15);
    }
};

// Tests para constructor
TEST_F(JugadorTest, ConstructorPorDefecto) {
    Jugador j;
    EXPECT_EQ(j.obtenerPuntaje(), 0);
}

TEST_F(JugadorTest, ConstructorConLimitePersonalizado) {
    Jugador j(15);
    EXPECT_EQ(j.obtenerPuntaje(), 0);
}

// Tests para recibirCarta (heredado de Participante)
TEST_F(JugadorTest, RecibirUnaCarta) {
    Jugador j;
    Carta carta("5", 5, "Corazones");
    j.recibirCarta(carta);
    EXPECT_EQ(j.obtenerPuntaje(), 5);
}

TEST_F(JugadorTest, RecibirMultiplesCartas) {
    Jugador j;
    j.recibirCarta(Carta("5", 5, "Corazones"));
    j.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_EQ(j.obtenerPuntaje(), 15);
}

// Tests para obtenerPuntaje (heredado de Participante)
TEST_F(JugadorTest, ObtenerPuntajeInicial) {
    Jugador j;
    EXPECT_EQ(j.obtenerPuntaje(), 0);
}

TEST_F(JugadorTest, ObtenerPuntajeConCartas) {
    Jugador j;
    j.recibirCarta(Carta("7", 7, "Corazones"));
    j.recibirCarta(Carta("8", 8, "Picas"));
    EXPECT_EQ(j.obtenerPuntaje(), 15);
}

// Tests para quiereMasCartas
TEST_F(JugadorTest, QuiereMasCartasConPuntajeMenor) {
    Jugador j(21);
    j.recibirCarta(Carta("5", 5, "Corazones"));
    EXPECT_TRUE(j.quiereMasCartas()); // 5 < 21
}

TEST_F(JugadorTest, QuiereMasCartasConPuntajeIgual) {
    Jugador j(21);
    j.recibirCarta(Carta("10", 10, "Corazones"));
    j.recibirCarta(Carta("10", 10, "Picas"));
    j.recibirCarta(Carta("1", 1, "Diamantes"));
    EXPECT_FALSE(j.quiereMasCartas()); // 21 no es < 21
}

TEST_F(JugadorTest, QuiereMasCartasConPuntajeMayor) {
    Jugador j(21);
    j.recibirCarta(Carta("10", 10, "Corazones"));
    j.recibirCarta(Carta("10", 10, "Picas"));
    j.recibirCarta(Carta("10", 10, "Diamantes"));
    EXPECT_FALSE(j.quiereMasCartas()); // 30 no es < 21 (Bust)
}

TEST_F(JugadorTest, QuiereMasCartasLimiteDiferente) {
    EXPECT_TRUE(jugadorLimite15.quiereMasCartas()); // 0 < 15
    
    jugadorLimite15.recibirCarta(Carta("10", 10, "Corazones"));
    EXPECT_TRUE(jugadorLimite15.quiereMasCartas()); // 10 < 15
    
    jugadorLimite15.recibirCarta(Carta("5", 5, "Picas"));
    EXPECT_FALSE(jugadorLimite15.quiereMasCartas()); // 15 no es < 15
}

// Tests para limpiarMano (heredado de Participante)
TEST_F(JugadorTest, LimpiarManoVacia) {
    Jugador j;
    j.limpiarMano();
    EXPECT_EQ(j.obtenerPuntaje(), 0);
}

TEST_F(JugadorTest, LimpiarManoConCartas) {
    Jugador j;
    j.recibirCarta(Carta("10", 10, "Corazones"));
    j.recibirCarta(Carta("10", 10, "Picas"));
    j.limpiarMano();
    EXPECT_EQ(j.obtenerPuntaje(), 0);
}

// Tests para mostrarMano (heredado de Participante)
TEST_F(JugadorTest, MostrarManoNoLanzaExcepcion) {
    Jugador j;
    EXPECT_NO_THROW(j.mostrarMano());
}

TEST_F(JugadorTest, MostrarManoConCartasNoLanzaExcepcion) {
    Jugador j;
    j.recibirCarta(Carta("10", 10, "Corazones"));
    j.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_NO_THROW(j.mostrarMano());
}

// Tests de integración
TEST_F(JugadorTest, SecuenciaJuegoCompleta) {
    Jugador j(21);
    
    // Primera ronda
    j.recibirCarta(Carta("10", 10, "Corazones"));
    EXPECT_TRUE(j.quiereMasCartas());
    EXPECT_EQ(j.obtenerPuntaje(), 10);
    
    j.recibirCarta(Carta("5", 5, "Picas"));
    EXPECT_TRUE(j.quiereMasCartas());
    EXPECT_EQ(j.obtenerPuntaje(), 15);
    
    j.recibirCarta(Carta("6", 6, "Diamantes"));
    EXPECT_FALSE(j.quiereMasCartas()); // 21
    EXPECT_EQ(j.obtenerPuntaje(), 21);
    
    // Segunda ronda
    j.limpiarMano();
    EXPECT_TRUE(j.quiereMasCartas());
    EXPECT_EQ(j.obtenerPuntaje(), 0);
}

// Tests con Ases
TEST_F(JugadorTest, JugadorConAs) {
    Jugador j;
    j.recibirCarta(Carta("As", 1, "Corazones"));
    j.recibirCarta(Carta("5", 5, "Picas"));
    EXPECT_EQ(j.obtenerPuntaje(), 16); // As como 11
}

TEST_F(JugadorTest, JugadorBlackjack) {
    Jugador j;
    j.recibirCarta(Carta("As", 1, "Corazones"));
    j.recibirCarta(Carta("Rey", 13, "Picas"));
    EXPECT_EQ(j.obtenerPuntaje(), 21); // Blackjack
    EXPECT_FALSE(j.quiereMasCartas());
}
