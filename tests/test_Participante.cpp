#include <gtest/gtest.h>
#include "../models/Participante.h"
#include "../models/Carta.h"

class ParticipanteTest : public ::testing::Test {
protected:
    Participante participante;
};

// Tests para constructor
TEST_F(ParticipanteTest, ConstructorPorDefecto) {
    EXPECT_EQ(participante.obtenerPuntaje(), 0);
}

// Tests para recibirCarta
TEST_F(ParticipanteTest, RecibirUnaCarta) {
    Carta carta("5", 5, "Corazones");
    participante.recibirCarta(carta);
    EXPECT_EQ(participante.obtenerPuntaje(), 5);
}

TEST_F(ParticipanteTest, RecibirMultiplesCartas) {
    participante.recibirCarta(Carta("5", 5, "Corazones"));
    participante.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_EQ(participante.obtenerPuntaje(), 15);
}

TEST_F(ParticipanteTest, RecibirTresCartas) {
    participante.recibirCarta(Carta("5", 5, "Corazones"));
    participante.recibirCarta(Carta("7", 7, "Picas"));
    participante.recibirCarta(Carta("9", 9, "Diamantes"));
    EXPECT_EQ(participante.obtenerPuntaje(), 21);
}

// Tests para obtenerPuntaje
TEST_F(ParticipanteTest, ObtenerPuntajeVacio) {
    EXPECT_EQ(participante.obtenerPuntaje(), 0);
}

TEST_F(ParticipanteTest, ObtenerPuntajeConUnaCartaNumerica) {
    participante.recibirCarta(Carta("7", 7, "Corazones"));
    EXPECT_EQ(participante.obtenerPuntaje(), 7);
}

TEST_F(ParticipanteTest, ObtenerPuntajeConFigura) {
    participante.recibirCarta(Carta("Rey", 13, "Picas"));
    EXPECT_EQ(participante.obtenerPuntaje(), 10);
}

TEST_F(ParticipanteTest, ObtenerPuntajeConAs) {
    participante.recibirCarta(Carta("As", 1, "Diamantes"));
    EXPECT_EQ(participante.obtenerPuntaje(), 11); // As como 11
}

TEST_F(ParticipanteTest, ObtenerPuntajeConMultiplesCartas) {
    participante.recibirCarta(Carta("5", 5, "Corazones"));
    participante.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_EQ(participante.obtenerPuntaje(), 15);
    
    participante.recibirCarta(Carta("6", 6, "Diamantes"));
    EXPECT_EQ(participante.obtenerPuntaje(), 21);
}

// Tests para limpiarMano
TEST_F(ParticipanteTest, LimpiarManoVacia) {
    participante.limpiarMano();
    EXPECT_EQ(participante.obtenerPuntaje(), 0);
}

TEST_F(ParticipanteTest, LimpiarManoConCartas) {
    participante.recibirCarta(Carta("10", 10, "Corazones"));
    participante.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_EQ(participante.obtenerPuntaje(), 20);
    
    participante.limpiarMano();
    EXPECT_EQ(participante.obtenerPuntaje(), 0);
}

TEST_F(ParticipanteTest, LimpiarYRecibirNuevasCartas) {
    participante.recibirCarta(Carta("5", 5, "Corazones"));
    participante.recibirCarta(Carta("5", 5, "Picas"));
    
    participante.limpiarMano();
    EXPECT_EQ(participante.obtenerPuntaje(), 0);
    
    participante.recibirCarta(Carta("9", 9, "Diamantes"));
    participante.recibirCarta(Carta("9", 9, "Tréboles"));
    EXPECT_EQ(participante.obtenerPuntaje(), 18);
}

// Tests para mostrarMano
TEST_F(ParticipanteTest, MostrarManoVaciaNoLanzaExcepcion) {
    EXPECT_NO_THROW(participante.mostrarMano());
}

TEST_F(ParticipanteTest, MostrarManoConCartasNoLanzaExcepcion) {
    participante.recibirCarta(Carta("10", 10, "Corazones"));
    participante.recibirCarta(Carta("10", 10, "Picas"));
    EXPECT_NO_THROW(participante.mostrarMano());
}

// Tests de secuencia
TEST_F(ParticipanteTest, SecuenciaCompleta) {
    // Verificar estado inicial
    EXPECT_EQ(participante.obtenerPuntaje(), 0);
    
    // Primera ronda
    participante.recibirCarta(Carta("10", 10, "Corazones"));
    EXPECT_EQ(participante.obtenerPuntaje(), 10);
    
    participante.recibirCarta(Carta("5", 5, "Picas"));
    EXPECT_EQ(participante.obtenerPuntaje(), 15);
    
    // Limpiar para segunda ronda
    participante.limpiarMano();
    EXPECT_EQ(participante.obtenerPuntaje(), 0);
    
    // Segunda ronda
    participante.recibirCarta(Carta("As", 1, "Diamantes"));
    participante.recibirCarta(Carta("10", 10, "Tréboles"));
    EXPECT_EQ(participante.obtenerPuntaje(), 21); // Blackjack
}

// Tests con casos especiales
TEST_F(ParticipanteTest, ParticipanteConMultiplesAses) {
    participante.recibirCarta(Carta("As", 1, "Corazones"));
    participante.recibirCarta(Carta("As", 1, "Picas"));
    EXPECT_EQ(participante.obtenerPuntaje(), 12); // 11 + 1
}

TEST_F(ParticipanteTest, ParticipanteBust) {
    participante.recibirCarta(Carta("10", 10, "Corazones"));
    participante.recibirCarta(Carta("10", 10, "Picas"));
    participante.recibirCarta(Carta("10", 10, "Diamantes"));
    EXPECT_EQ(participante.obtenerPuntaje(), 30); // Bust
}

TEST_F(ParticipanteTest, ParticipanteConTodasLasFiguras) {
    participante.recibirCarta(Carta("Jota", 11, "Corazones"));
    participante.recibirCarta(Carta("Reina", 12, "Picas"));
    participante.recibirCarta(Carta("Rey", 13, "Diamantes"));
    EXPECT_EQ(participante.obtenerPuntaje(), 30); // 10 + 10 + 10
}
