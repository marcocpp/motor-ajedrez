#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>
#include "Casilla.hpp"

class Ficha;

class Tablero {
public:
    static constexpr int TAM = 8;

    Tablero();
    ~Tablero() = default;

    void dibujarTablero();

private:
    Casilla m_casillas[TAM][TAM];
};

#endif // TABLERO_HPP