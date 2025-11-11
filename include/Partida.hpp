#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "Tablero.hpp"
#include "Jugador.hpp"
#include "Ficha.hpp"

class Partida {
public:
    Partida();
    ~Partida() = default;

    void iniciarPartida();
    void gestionarTurno();
    void ejecutarMovimiento();



private:

};

#endif // PARTIDA_HPP