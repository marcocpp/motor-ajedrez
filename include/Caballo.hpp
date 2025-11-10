#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "Ficha.hpp"


class Caballo : public Ficha {
public:
    Caballo(Color color);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Caballo() = default;

};

#endif // CABALLO_HPP