#ifndef CASILLA_HPP
#define CASILLA_HPP

#include <memory>
#include "Ficha.hpp"

class Casilla {
public:
    Casilla() = default;

    void setFicha(std::unique_ptr<Ficha> ficha);
    Ficha* getFicha() const;
    std::unique_ptr<Ficha> quitarFicha();

private:
    std::unique_ptr<Ficha> m_ficha;
};

#endif // CASILLA_HPP