#include "Casilla.hpp"

Casilla::Casilla() : m_fichaActual(nullptr) {

}

void Casilla::setFicha(Ficha* ficha) {
    m_fichaActual = ficha;
}