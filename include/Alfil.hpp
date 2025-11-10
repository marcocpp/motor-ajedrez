#ifndef ALFIL_HPP
#define ALFIL_HPP

#include "Ficha.hpp"


class Alfil : public Ficha {
public:
    Alfil(Color color);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Alfil() = default;

};

#endif // ALFIL_HPP