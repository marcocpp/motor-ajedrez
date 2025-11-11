#include "Casilla.hpp"


void Casilla::setFicha(std::unique_ptr<Ficha> ficha) {
    m_ficha = std::move(ficha);
}

Ficha* Casilla::getFicha() const {
    return m_ficha.get();
}


std::unique_ptr<Ficha> Casilla::quitarFicha() {
    // Mueve el unique_ptr de m_ficha para pasarselo al return, así m_ficha se queda vacio (nullptr)
    return std::move(m_ficha);;
}