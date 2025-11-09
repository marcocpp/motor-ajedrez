#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>
#include "Casilla.hpp"

class Ficha;

class Tablero {
public:
    static constexpr int TAM = 8;

    Tablero();

private:
    Casilla m_casillas[TAM][TAM];
    std::vector<Ficha*> m_fichasTablero;
};

#endif // TABLERO_HPP