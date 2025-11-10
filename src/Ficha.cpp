#include "Ficha.hpp"

Ficha::Ficha(Color color, char icono) : m_color(color), m_icono(icono) {}

Color Ficha::getColor() const {
    return m_color;
}

char Ficha::getIcono() const {
    return m_icono;
}