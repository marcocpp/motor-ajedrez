#include "Ficha.hpp"

Ficha::Ficha(Color color) : m_color(color) {}

Color Ficha::getColor() const {
    return m_color;
}