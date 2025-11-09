#ifndef PEON_HPP
#define PEON_HPP

#include "Ficha.hpp"


class Peon : public Ficha {
public:
    Peon(Color color);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Peon() = default;

};

#endif // PEON_HPP