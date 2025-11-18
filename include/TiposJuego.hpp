#ifndef TIPOSJUEGO_HPP
#define TIPOSJUEGO_HPP

#include <cstdlib>

enum class Color {
    BLANCO,
    NEGRO
};


struct Coordenada {
    int fila;
    int col;
};


inline void limpiarPantalla() {
#ifdef _WIN32
    // Para Windows
    system("cls");
#else
    // Para Linux y macOS (y otros sistemas tipo UNIX)
    system("clear");
#endif
}

#endif // TIPOSJUEGO_HPP