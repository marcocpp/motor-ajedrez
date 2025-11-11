#include "Jugador.hpp"

Jugador::Jugador(Color color) : m_color(color) {

}

Color Jugador::getColor() const {
    return m_color;
}

std::string Jugador::getNombre() const {
    return m_nombre;
}