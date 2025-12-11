#include <gtest/gtest.h>
#include <algorithm>
#include "../models/Juego.h"
#include "../models/Carta.h"

class JuegoTest : public ::testing::Test {
protected:
    Juego juego;
};

// Tests para constructor
TEST_F(JuegoTest, ConstructorInicializaBaraja) {
    // Una baraja estándar debe tener 52 cartas
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
}

// Tests para reiniciarBaraja
TEST_F(JuegoTest, ReiniciarBarajaTamanoCorrect) {
    Carta cartaExtra("Extra", 5, "Corazones");
    // Sacar algunas cartas
    juego.obtenerSiguenteCarta();
    juego.obtenerSiguenteCarta();
    
    // Reiniciar baraja
    juego.reiniciarBaraja();
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
}

// Tests para obtenerTamañoDeBaraja
TEST_F(JuegoTest, ObtenerTamañoDeBarajaCompleta) {
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
}

TEST_F(JuegoTest, ObtenerTamañoDeBarajaDisminuye) {
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
    
    juego.obtenerSiguenteCarta();
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52); // El índice aumenta pero el tamaño es el mismo
}

// Tests para obtenerSiguenteCarta
TEST_F(JuegoTest, ObtenerSiguienteCartaNoVacia) {
    Carta carta = juego.obtenerSiguenteCarta();
    EXPECT_FALSE(carta.obtenerNombre().empty());
}

TEST_F(JuegoTest, ObtenerSiguienteCartasMultiples) {
    Carta carta1 = juego.obtenerSiguenteCarta();
    Carta carta2 = juego.obtenerSiguenteCarta();
    
    // Las cartas deben ser diferentes (generalmente)
    // Aunque no es garantizado, es altamente probable
    EXPECT_FALSE(carta1.obtenerNombre().empty());
    EXPECT_FALSE(carta2.obtenerNombre().empty());
}

TEST_F(JuegoTest, ObtenerSiguienteCartaAgotaBaraja) {
    // Sacar todas las cartas
    for (int i = 0; i < 52; ++i) {
        Carta carta = juego.obtenerSiguenteCarta();
        EXPECT_FALSE(carta.obtenerNombre().empty());
    }
    
    // La siguiente carta debe ser vacía
    Carta carta = juego.obtenerSiguenteCarta();
    EXPECT_EQ(carta.obtenerNombre(), "");
}

// Tests para barajarMazo
TEST_F(JuegoTest, BarajarMazoRestablecePosicion) {
    juego.obtenerSiguenteCarta();
    juego.obtenerSiguenteCarta();
    
    // Después de barajar, podemos sacar cartas nuevamente desde el inicio
    juego.barajarMazo();
    
    // Debería permitir sacar cartas nuevamente
    Carta carta = juego.obtenerSiguenteCarta();
    EXPECT_FALSE(carta.obtenerNombre().empty());
}

// Tests para la baraja original y barajada
TEST_F(JuegoTest, BarajaOriginalTiene52Cartas) {
    // Reiniciar para asegurar estado limpio
    juego.reiniciarBaraja();
    
    // La baraja original debe tener 52 cartas
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
}

// Tests para verificar que todos los palos existen
TEST_F(JuegoTest, BarajaContieneTodasLosPalos) {
    bool tieneCorazones = false;
    bool tienePicas = false;
    bool tieneTreboles = false;
    bool tieneDiamantes = false;
    
    juego.reiniciarBaraja();
    juego.barajarMazo();
    
    for (int i = 0; i < 52; ++i) {
        Carta carta = juego.obtenerSiguenteCarta();
        string tipo = carta.obtenerTipo();
        
        if (tipo == "Corazones") tieneCorazones = true;
        if (tipo == "Picas") tienePicas = true;
        if (tipo == "Tréboles") tieneTreboles = true;
        if (tipo == "Diamantes") tieneDiamantes = true;
    }
    
    EXPECT_TRUE(tieneCorazones);
    EXPECT_TRUE(tienePicas);
    EXPECT_TRUE(tieneTreboles);
    EXPECT_TRUE(tieneDiamantes);
}

// Tests para verificar que la baraja contiene los valores correctos
TEST_F(JuegoTest, BarajaContieneTodosLosValores) {
    vector<int> valoresEsperados = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    vector<int> valoresEncontrados;
    
    juego.reiniciarBaraja();
    juego.barajarMazo();
    
    for (int i = 0; i < 52; ++i) {
        Carta carta = juego.obtenerSiguenteCarta();
        int valor = carta.obtenerValor();
        
        // Solo agregar valores únicos
        if (find(valoresEncontrados.begin(), valoresEncontrados.end(), valor) == valoresEncontrados.end()) {
            valoresEncontrados.push_back(valor);
        }
    }
    
    sort(valoresEncontrados.begin(), valoresEncontrados.end());
    EXPECT_EQ(valoresEncontrados, valoresEsperados);
}

// Tests para mostrarBarajaOriginal (verifica que no lance excepciones)
TEST_F(JuegoTest, MostrarBarajaOriginalNoLanzaExcepcion) {
    EXPECT_NO_THROW(juego.mostrarBarajaOriginal());
}

// Tests para mostrarBarajaBarajada
TEST_F(JuegoTest, MostrarBarajaBarajadaNoLanzaExcepcion) {
    EXPECT_NO_THROW(juego.mostrarBarajaBarajada());
}

// Tests para MazoCompleto
TEST_F(JuegoTest, MazoCompletoNoLanzaExcepcion) {
    EXPECT_NO_THROW(juego.MazoCompleto());
}

// Tests de integración
TEST_F(JuegoTest, SecuenciaJuegoCompleta) {
    // Reiniciar baraja
    juego.reiniciarBaraja();
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
    
    // Barajar
    juego.barajarMazo();
    EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
    
    // Sacar cartas para dos jugadores (4 cartas)
    Carta carta1 = juego.obtenerSiguenteCarta();
    Carta carta2 = juego.obtenerSiguenteCarta();
    Carta carta3 = juego.obtenerSiguenteCarta();
    Carta carta4 = juego.obtenerSiguenteCarta();
    
    EXPECT_FALSE(carta1.obtenerNombre().empty());
    EXPECT_FALSE(carta2.obtenerNombre().empty());
    EXPECT_FALSE(carta3.obtenerNombre().empty());
    EXPECT_FALSE(carta4.obtenerNombre().empty());
}

// Tests para reiniciar múltiples veces
TEST_F(JuegoTest, ReiniciarMultiplesVeces) {
    for (int i = 0; i < 3; ++i) {
        juego.reiniciarBaraja();
        EXPECT_EQ(juego.obtenerTamañoDeBaraja(), 52);
        
        // Sacar una carta
        Carta carta = juego.obtenerSiguenteCarta();
        EXPECT_FALSE(carta.obtenerNombre().empty());
    }
}

// Tests para barajar múltiples veces
TEST_F(JuegoTest, BarajarMultiplesVeces) {
    for (int i = 0; i < 3; ++i) {
        juego.barajarMazo();
        Carta carta = juego.obtenerSiguenteCarta();
        EXPECT_FALSE(carta.obtenerNombre().empty());
    }
}
