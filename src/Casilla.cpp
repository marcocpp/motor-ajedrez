#include "Casilla.hpp"


void Casilla::setFicha(std::unique_ptr<Ficha> ficha) {
    m_fichaActual = std::move(ficha);
}

Ficha* Casilla::getFicha() {
    return m_fichaActual.get();
}
