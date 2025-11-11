#include "Casilla.hpp"


void Casilla::setFicha(std::unique_ptr<Ficha> ficha) {
    m_ficha = std::move(ficha);
}

Ficha* Casilla::getFicha() const {
    return m_ficha.get();
}
