#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "Ficha.hpp"


class Caballo : public Ficha {
public:
    Caballo(Color color, char icono);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Caballo() noexcept override = default;
};

#endif // CABALLO_HPP