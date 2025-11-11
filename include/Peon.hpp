#ifndef PEON_HPP
#define PEON_HPP

#include "Ficha.hpp"

class Peon : public Ficha
{
public:
    Peon(Color color, char icono);
    bool movimientoValido(); // TODO Hay q redefinirla

    virtual ~Peon() noexcept override = default;
};

#endif // PEON_HPP