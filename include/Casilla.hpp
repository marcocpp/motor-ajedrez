#ifndef CASILLA_HPP
#define CASILLA_HPP

#include <memory>
#include "Ficha.hpp"

class Casilla {
public:
    Casilla() = default;

    void setFicha(std::unique_ptr<Ficha> ficha);
    Ficha* getFicha();

private:
    std::unique_ptr<Ficha> m_fichaActual; // Si ficha = nullptr, la casilla está vacia
};

#endif // CASILLA_HPP