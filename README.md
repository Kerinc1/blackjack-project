/*
    Proyecto: Blackjack
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos.

    Autor: Jhon Esteban Acosta Gutierrez - 2518388
           Benjamin Lopera Ochoa - 2515144-2724
           Jhonny Alexander Moreno Florez - 2522112

    Fecha: Octubre/noviembre 2025
*/

# Blackjack (Proyecto FPOO)

Pequeño juego de Blackjack desarrollado como proyecto del curso Fundamentos de Programación Orientada a Objetos (FPOO).

## Requisitos
- Visual Studio Code con la extensión "Dev Containers" o "Remote - Containers".
- Dev container provisto (Debian GNU/Linux 13) — ya incluye gcc, g++, cmake, make y herramientas de depuración.
- Extensiones recomendadas: C/C++ (Microsoft), CMake Tools (opcional).

## Abrir en el Dev Container
1. Abre la carpeta del proyecto en VS Code.
2. Abre la paleta (Ctrl+Shift+P) y selecciona "Remote-Containers: Reopen in Container" o usa el ícono de abajo a la izquierda.
3. VS Code construirá y abrirá el contenedor; cuando termine, estarás dentro del entorno Debian con las herramientas ya instaladas.

## Compilar y ejecutar

### Opción A — Usando VS Code (F5) - Recomendado
- Presiona **F5** para compilar y ejecutar usando la configuración de lanzamiento (`.vscode/launch.json`) y las tareas definidas (`.vscode/tasks.json`).

### Opción B — Línea de comando con CMake (desde el contenedor)
```bash
# desde la raíz del proyecto
mkdir -p build
cd build
cmake ..
make
./blackjack
```

### Opción C — Compilación rápida con g++ (alternativa)
```bash
# desde la raíz del proyecto
g++ -std=c++17 -Wall -g \
  -I./models -I./views -I./controllers \
  models/*.cpp views/*.cpp controllers/*.cpp *.cpp \
  -o blackjack
./blackjack
```

### Opción D — Usando la tarea de VS Code
1. Abre la paleta de comandos: **Ctrl+Shift+P**
2. Busca y selecciona: **"Tasks: Run Task"**
3. Selecciona: **"Build Blackjack (g++)"**

---

## Compilar y ejecutar las pruebas unitarias

### Pruebas con Google Test (112 pruebas)
```bash
cd /workspaces/blackJack/build
ctest --verbose
```

O ejecutar suites específicas:
```bash
./test_carta
./test_mano
./test_participante
./test_jugador
./test_juego
./test_crupier
```

### Ejemplo de pruebas con Assert
```bash
cd /workspaces/blackJack
./examples_assert
```

Para más información sobre las pruebas, ver [TEST_README.md](TEST_README.md)

## Estructura del proyecto
├── models/
│   ├── Carta.h
│   ├── Carta.cpp
│   ├── Crupier.h
│   ├── Crupier.cpp
│   ├── Juego.h
│   ├── Juego.cpp
│   ├── Jugador.h
│   ├── Jugador.cpp
│   ├── Mano.h
│   ├── Mano.cpp
│   ├── Participante.h
│   └── Participante.cpp
├── views/
│   ├── GameView.h
│   └── GameView.cpp
└── controllers/
    ├── GameController.h
    └── GameController.cpp
- main.cpp
- .vscode/ (launch.json, tasks.json)
- README.md

## Problemas comunes
- Si F5 no compila: abre la pestaña "Terminal" → ejecuta la tarea de compilación manualmente o usa los comandos de CMake indicados arriba.
- Errores de enlace: verifica que todos los .cpp estén incluidos en la compilación.
- Si las pruebas no compilan: `sudo apt-get install libgtest-dev cmake`

## Contribuciones
Este es un proyecto académico del curso FPOO. Para contribuciones o mejoras, por favor abrir un issue o pull request.
