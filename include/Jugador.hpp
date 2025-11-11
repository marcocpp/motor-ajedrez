#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "TiposJuego.hpp"
#include "Ficha.hpp"

class Jugador {
public:

    Jugador(Color color);
    ~Jugador() = default;

    Color getColor() const;
    std::string getNombre() const;

    void solicitarMovimiento(); // Solicita el movimiento y la clase Partida ejecuta ese movimiento si es valido, si no lo es vuelve a solicitar


private:
    Color m_color;
    std::string m_nombre;
    std::vector<std::unique_ptr<Ficha>> m_fichasCapturadas;
};

#endif // JUGADOR_HPP