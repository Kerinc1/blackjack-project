cmake_minimum_required(VERSION 3.10)
project(blackjack_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar Google Test
find_package(GTest REQUIRED)

# Incluir directorios de headers
include_directories(${CMAKE_SOURCE_DIR}/models)
include_directories(${CMAKE_SOURCE_DIR}/views)
include_directories(${CMAKE_SOURCE_DIR}/controllers)

# Archivos fuente de los modelos
set(MODEL_SOURCES
    models/Carta.cpp
    models/Carta.h
    models/Mano.cpp
    models/Mano.h
    models/Participante.cpp
    models/Participante.h
    models/Jugador.cpp
    models/Jugador.h
    models/Crupier.cpp
    models/Crupier.h
    models/Juego.cpp
    models/Juego.h
)

# Crear ejecutables de prueba
add_executable(test_carta
    tests/test_Carta.cpp
    models/Carta.cpp
)
target_link_libraries(test_carta GTest::gtest GTest::gtest_main)

add_executable(test_mano
    tests/test_Mano.cpp
    models/Mano.cpp
    models/Carta.cpp
)
target_link_libraries(test_mano GTest::gtest GTest::gtest_main)

add_executable(test_participante
    tests/test_Participante.cpp
    models/Participante.cpp
    models/Mano.cpp
    models/Carta.cpp
)
target_link_libraries(test_participante GTest::gtest GTest::gtest_main)

add_executable(test_jugador
    tests/test_Jugador.cpp
    models/Jugador.cpp
    models/Participante.cpp
    models/Mano.cpp
    models/Carta.cpp
)
target_link_libraries(test_jugador GTest::gtest GTest::gtest_main)

add_executable(test_juego
    tests/test_Juego.cpp
    models/Juego.cpp
    models/Carta.cpp
)
target_link_libraries(test_juego GTest::gtest GTest::gtest_main)

add_executable(test_crupier
    tests/test_Crupier.cpp
    models/Crupier.cpp
    models/Participante.cpp
    models/Juego.cpp
    models/Mano.cpp
    models/Carta.cpp
)
target_link_libraries(test_crupier GTest::gtest GTest::gtest_main)

# Habilitar pruebas
enable_testing()
add_test(NAME CartaTest COMMAND test_carta)
add_test(NAME ManoTest COMMAND test_mano)
add_test(NAME ParticipanteTest COMMAND test_participante)
add_test(NAME JugadorTest COMMAND test_jugador)
add_test(NAME JuegoTest COMMAND test_juego)
add_test(NAME CrupierTest COMMAND test_crupier)
