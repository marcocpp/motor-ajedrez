#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "Tablero.hpp"
#include "Jugador.hpp"
#include "Ficha.hpp"

class Partida {
public:
    Partida(std::string nombre_j1, std::string nombre_j2);
    ~Partida() = default;


    void iniciarPartida();
    std::pair<bool, bool> validarMovimiento(Coordenada origen, Coordenada destino, Ficha* ficha_org, Ficha* ficha_dest);


private:
    Jugador m_jugador1;
    Jugador m_jugador2;
    Jugador* m_jugadorActual; // Para saber a quien le toca
    Tablero m_tablero;

    bool m_juegoEnCurso = false;

};

#endif // PARTIDA_HPP