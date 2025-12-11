#include <gtest/gtest.h>
#include "../models/Mano.h"
#include "../models/Carta.h"

class ManoTest : public ::testing::Test {
protected:
    Mano manoVacia;
    Mano manoConCartas;

    void SetUp() override {
        // La mano vacía se inicializa automáticamente
        // Agregar cartas a la segunda mano
        manoConCartas.agregarAMano(Carta("5", 5, "Corazones"));
        manoConCartas.agregarAMano(Carta("6", 6, "Picas"));
    }
};

// Tests para constructor
TEST_F(ManoTest, ConstructorCreaManoVacia) {
    Mano mano;
    EXPECT_EQ(mano.calcularValor(), 0);
}

// Tests para agregarAMano
TEST_F(ManoTest, AgregarUnaCarta) {
    Mano mano;
    Carta carta("5", 5, "Corazones");
    mano.agregarAMano(carta);
    EXPECT_EQ(mano.calcularValor(), 5);
}

TEST_F(ManoTest, AgregarMultiplesCartas) {
    Mano mano;
    mano.agregarAMano(Carta("5", 5, "Corazones"));
    mano.agregarAMano(Carta("6", 6, "Picas"));
    mano.agregarAMano(Carta("4", 4, "Diamantes"));
    EXPECT_EQ(mano.calcularValor(), 15);
}

// Tests para calcularValor - Cartas numéricas simples
TEST_F(ManoTest, CalcularValorCartasNumericas) {
    Mano mano;
    mano.agregarAMano(Carta("2", 2, "Corazones"));
    mano.agregarAMano(Carta("3", 3, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 5);
}

TEST_F(ManoTest, CalcularValorDoble10) {
    Mano mano;
    mano.agregarAMano(Carta("10", 10, "Corazones"));
    mano.agregarAMano(Carta("10", 10, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 20);
}

// Tests para calcularValor - Con figuras (J, Q, K)
TEST_F(ManoTest, CalcularValorConFiguras) {
    Mano mano;
    mano.agregarAMano(Carta("Jota", 11, "Corazones"));
    EXPECT_EQ(mano.calcularValor(), 10); // Las figuras valen 10 en Blackjack
}

TEST_F(ManoTest, CalcularValorReina) {
    Mano mano;
    mano.agregarAMano(Carta("Reina", 12, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 10);
}

TEST_F(ManoTest, CalcularValorRey) {
    Mano mano;
    mano.agregarAMano(Carta("Rey", 13, "Corazones"));
    EXPECT_EQ(mano.calcularValor(), 10);
}

TEST_F(ManoTest, CalcularValorMulipleFiguras) {
    Mano mano;
    mano.agregarAMano(Carta("Jota", 11, "Corazones"));
    mano.agregarAMano(Carta("Reina", 12, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 20);
}

// Tests para calcularValor - Con ases
TEST_F(ManoTest, CalcularValorUnAsComo11) {
    Mano mano;
    mano.agregarAMano(Carta("As", 1, "Corazones"));
    mano.agregarAMano(Carta("5", 5, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 16); // As como 11 + 5 = 16
}

TEST_F(ManoTest, CalcularValorUnAsComo1) {
    Mano mano;
    mano.agregarAMano(Carta("As", 1, "Corazones"));
    mano.agregarAMano(Carta("10", 10, "Picas"));
    mano.agregarAMano(Carta("5", 5, "Diamantes"));
    EXPECT_EQ(mano.calcularValor(), 16); // As como 1 + 10 + 5 = 16
}

TEST_F(ManoTest, CalcularValorDosAses) {
    Mano mano;
    mano.agregarAMano(Carta("As", 1, "Corazones"));
    mano.agregarAMano(Carta("As", 1, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 12); // Un As como 11 + otro como 1 = 12
}

TEST_F(ManoTest, CalcularValorTresAses) {
    Mano mano;
    mano.agregarAMano(Carta("As", 1, "Corazones"));
    mano.agregarAMano(Carta("As", 1, "Picas"));
    mano.agregarAMano(Carta("As", 1, "Diamantes"));
    EXPECT_EQ(mano.calcularValor(), 13); // Un As como 11 + dos como 1 = 13
}

TEST_F(ManoTest, CalcularValorAsConFigura) {
    Mano mano;
    mano.agregarAMano(Carta("As", 1, "Corazones"));
    mano.agregarAMano(Carta("Rey", 13, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 21); // Blackjack: As como 11 + Rey (10) = 21
}

// Tests para calcularValor - Casos complejos
TEST_F(ManoTest, CalcularValor21Simples) {
    Mano mano;
    mano.agregarAMano(Carta("5", 5, "Corazones"));
    mano.agregarAMano(Carta("9", 9, "Picas"));
    mano.agregarAMano(Carta("7", 7, "Diamantes"));
    EXPECT_EQ(mano.calcularValor(), 21);
}

TEST_F(ManoTest, CalcularValorMasDeVeintiuno) {
    Mano mano;
    mano.agregarAMano(Carta("10", 10, "Corazones"));
    mano.agregarAMano(Carta("10", 10, "Picas"));
    mano.agregarAMano(Carta("5", 5, "Diamantes"));
    EXPECT_EQ(mano.calcularValor(), 25); // Bust
}

TEST_F(ManoTest, CalcularValorAsNoSeConvierteAOnceQueSumaria22) {
    Mano mano;
    mano.agregarAMano(Carta("As", 1, "Corazones"));
    mano.agregarAMano(Carta("10", 10, "Picas"));
    mano.agregarAMano(Carta("5", 5, "Diamantes"));
    EXPECT_EQ(mano.calcularValor(), 16); // As como 1 + 10 + 5 = 16
}

// Tests para limpiarMano
TEST_F(ManoTest, LimpiarManoVacia) {
    Mano mano;
    mano.limpiarMano();
    EXPECT_EQ(mano.calcularValor(), 0);
}

TEST_F(ManoTest, LimpiarManoConCartas) {
    Mano mano;
    mano.agregarAMano(Carta("5", 5, "Corazones"));
    mano.agregarAMano(Carta("6", 6, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 11);
    
    mano.limpiarMano();
    EXPECT_EQ(mano.calcularValor(), 0);
}

TEST_F(ManoTest, LimpiarYAgregarNuevasCartas) {
    Mano mano;
    mano.agregarAMano(Carta("5", 5, "Corazones"));
    mano.agregarAMano(Carta("6", 6, "Picas"));
    
    mano.limpiarMano();
    EXPECT_EQ(mano.calcularValor(), 0);
    
    mano.agregarAMano(Carta("10", 10, "Diamantes"));
    mano.agregarAMano(Carta("10", 10, "Tréboles"));
    EXPECT_EQ(mano.calcularValor(), 20);
}

// Tests de integración
TEST_F(ManoTest, SecuenciaCompleta) {
    Mano mano;
    
    // Primera ronda: agregar cartas
    mano.agregarAMano(Carta("5", 5, "Corazones"));
    EXPECT_EQ(mano.calcularValor(), 5);
    
    mano.agregarAMano(Carta("10", 10, "Picas"));
    EXPECT_EQ(mano.calcularValor(), 15);
    
    // Segunda ronda: limpiar y nuevas cartas
    mano.limpiarMano();
    EXPECT_EQ(mano.calcularValor(), 0);
    
    mano.agregarAMano(Carta("As", 1, "Diamantes"));
    mano.agregarAMano(Carta("10", 10, "Corazones"));
    EXPECT_EQ(mano.calcularValor(), 21);
}

// Tests para mostrarMano (verifica que no lance excepciones)
TEST_F(ManoTest, MostrarManoNoLanzaExcepcion) {
    Mano mano;
    EXPECT_NO_THROW(mano.mostrarMano());
}

TEST_F(ManoTest, MostrarManoConCartasNoLanzaExcepcion) {
    Mano mano;
    mano.agregarAMano(Carta("5", 5, "Corazones"));
    mano.agregarAMano(Carta("10", 10, "Picas"));
    EXPECT_NO_THROW(mano.mostrarMano());
}