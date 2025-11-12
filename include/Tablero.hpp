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
    void quitarFicha(std::unique_ptr<Ficha> ficha);
    void moverFicha(Coordenada origen, Coordenada destino); // Mover ficha una vez comprobado en movimiento
    Ficha* getFichaCasilla(Coordenada casilla) const;
    bool caminoDespejado(Coordenada origen, Coordenada destino);

private:
    Casilla m_casillas[TAM][TAM];
};

#endif // TABLERO_HPP