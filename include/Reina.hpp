#ifndef REINA_HPP
#define REINA_HPP

#include "Ficha.hpp"


class Reina : public Ficha {
public:
    Reina(Color color);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Reina() = default;

};

#endif // REINA_HPP