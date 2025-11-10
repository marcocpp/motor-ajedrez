#ifndef REY_HPP
#define REY_HPP

#include "Ficha.hpp"


class Rey : public Ficha {
public:
    Rey(Color color);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Rey() = default;

};

#endif // REY_HPP