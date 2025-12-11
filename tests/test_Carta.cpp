#include <gtest/gtest.h>
#include "../models/Carta.h"

class CartaTest : public ::testing::Test {
protected:
    Carta cartaVacia;
    Carta cartaNumerica;
    Carta cartaFigura;
    Carta cartaAs;

    void SetUp() override {
        cartaNumerica = Carta("5", 5, "Corazones");
        cartaFigura = Carta("Rey", 13, "Picas");
        cartaAs = Carta("As", 1, "Diamantes");
    }
};

// Tests para constructor sin parámetros
TEST_F(CartaTest, ConstructorPorDefecto) {
    Carta carta;
    EXPECT_EQ(carta.obtenerNombre(), "");
    EXPECT_EQ(carta.obtenerValor(), 0);
    EXPECT_EQ(carta.obtenerTipo(), "");
}

// Tests para constructor con parámetros
TEST_F(CartaTest, ConstructorConParametros) {
    Carta carta("Rey", 13, "Picas");
    EXPECT_EQ(carta.obtenerNombre(), "Rey");
    EXPECT_EQ(carta.obtenerValor(), 13);
    EXPECT_EQ(carta.obtenerTipo(), "Picas");
}

// Tests para obtenerNombre
TEST_F(CartaTest, ObtenerNombreCartaNumerica) {
    EXPECT_EQ(cartaNumerica.obtenerNombre(), "5");
}

TEST_F(CartaTest, ObtenerNombreCartaFigura) {
    EXPECT_EQ(cartaFigura.obtenerNombre(), "Rey");
}

TEST_F(CartaTest, ObtenerNombreCartaAs) {
    EXPECT_EQ(cartaAs.obtenerNombre(), "As");
}

// Tests para obtenerValor
TEST_F(CartaTest, ObtenerValorCartaNumerica) {
    EXPECT_EQ(cartaNumerica.obtenerValor(), 5);
}

TEST_F(CartaTest, ObtenerValorCartaFigura) {
    EXPECT_EQ(cartaFigura.obtenerValor(), 13);
}

TEST_F(CartaTest, ObtenerValorCartaAs) {
    EXPECT_EQ(cartaAs.obtenerValor(), 1);
}

// Tests para obtenerTipo
TEST_F(CartaTest, ObtenerTipoCorazones) {
    EXPECT_EQ(cartaNumerica.obtenerTipo(), "Corazones");
}

TEST_F(CartaTest, ObtenerTipoPicas) {
    EXPECT_EQ(cartaFigura.obtenerTipo(), "Picas");
}

TEST_F(CartaTest, ObtenerTipoDiamantes) {
    EXPECT_EQ(cartaAs.obtenerTipo(), "Diamantes");
}

// Tests para establecerNombre
TEST_F(CartaTest, EstablecerNombre) {
    Carta carta;
    carta.establecerNombre("Jota");
    EXPECT_EQ(carta.obtenerNombre(), "Jota");
}

TEST_F(CartaTest, EstablecerNombreMultipleVeces) {
    Carta carta("5", 5, "Corazones");
    carta.establecerNombre("Reina");
    EXPECT_EQ(carta.obtenerNombre(), "Reina");
    carta.establecerNombre("As");
    EXPECT_EQ(carta.obtenerNombre(), "As");
}

// Tests para establecerValor
TEST_F(CartaTest, EstablecerValor) {
    Carta carta;
    carta.establecerValor(10);
    EXPECT_EQ(carta.obtenerValor(), 10);
}

TEST_F(CartaTest, EstablecerValorMultipleVeces) {
    Carta carta("5", 5, "Corazones");
    carta.establecerValor(12);
    EXPECT_EQ(carta.obtenerValor(), 12);
    carta.establecerValor(1);
    EXPECT_EQ(carta.obtenerValor(), 1);
}

// Tests para establecerTipo
TEST_F(CartaTest, EstablecerTipo) {
    Carta carta;
    carta.establecerTipo("Tréboles");
    EXPECT_EQ(carta.obtenerTipo(), "Tréboles");
}

TEST_F(CartaTest, EstablecerTipoMultipleVeces) {
    Carta carta("5", 5, "Corazones");
    carta.establecerTipo("Picas");
    EXPECT_EQ(carta.obtenerTipo(), "Picas");
    carta.establecerTipo("Diamantes");
    EXPECT_EQ(carta.obtenerTipo(), "Diamantes");
}

// Tests de validación de valores
TEST_F(CartaTest, ValoresValidosCartasNumericas) {
    for (int i = 2; i <= 10; ++i) {
        Carta carta(to_string(i), i, "Corazones");
        EXPECT_EQ(carta.obtenerValor(), i);
    }
}

TEST_F(CartaTest, ValoresFiguras) {
    Carta jota("Jota", 11, "Picas");
    Carta reina("Reina", 12, "Corazones");
    Carta rey("Rey", 13, "Tréboles");
    
    EXPECT_EQ(jota.obtenerValor(), 11);
    EXPECT_EQ(reina.obtenerValor(), 12);
    EXPECT_EQ(rey.obtenerValor(), 13);
}

// Tests de todos los tipos de palo
TEST_F(CartaTest, TodosLosPalos) {
    Carta corazones("As", 1, "Corazones");
    Carta picas("As", 1, "Picas");
    Carta treboles("As", 1, "Tréboles");
    Carta diamantes("As", 1, "Diamantes");
    
    EXPECT_EQ(corazones.obtenerTipo(), "Corazones");
    EXPECT_EQ(picas.obtenerTipo(), "Picas");
    EXPECT_EQ(treboles.obtenerTipo(), "Tréboles");
    EXPECT_EQ(diamantes.obtenerTipo(), "Diamantes");
}
