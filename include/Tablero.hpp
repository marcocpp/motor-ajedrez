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
    void setFicha(std::unique_ptr<Ficha> ficha, Coordenada destino); // añadir como parametro tambien las coordenadas a donde lo quiero poner 

private:
    Casilla m_casillas[TAM][TAM];
};

#endif // TABLERO_HPP