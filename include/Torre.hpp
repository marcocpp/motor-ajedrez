#ifndef TORRE_HPP
#define TORRE_HPP

#include "Ficha.hpp"


class Torre : public Ficha {
public:
    Torre(Color color);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Torre() = default;

};

#endif // TORRE_HPP