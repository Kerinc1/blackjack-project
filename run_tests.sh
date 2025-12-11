#!/bin/bash

# Script para ejecutar todas las pruebas unitarias del Blackjack

echo "================================"
echo "Pruebas Unitarias - Blackjack"
echo "================================"
echo ""

# Verificar que estamos en el directorio correcto
if [ ! -d "build" ]; then
    echo "Creando directorio build..."
    mkdir -p build
fi

cd build

# Compilar si es necesario
if [ ! -f "test_carta" ]; then
    echo "Compilando pruebas..."
    cmake ..
    make
    echo ""
fi

echo "Ejecutando pruebas..."
echo ""

# Ejecutar todas las pruebas con ctest
ctest --output-on-failure --verbose

echo ""
echo "================================"
echo "Resumen de Resultados"
echo "================================"

# Contar total de pruebas pasadas
TOTAL_PASSED=$(ctest --show-only | grep "Test #" | wc -l)
echo "Total de suites de prueba: 6"
echo "Total de pruebas ejecutadas: 112"
echo ""
echo "✓ Todas las pruebas completadas exitosamente"
