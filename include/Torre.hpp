#ifndef TORRE_HPP
#define TORRE_HPP

#include "Ficha.hpp"


class Torre : public Ficha {
public:
    Torre(Color color, char icono);
    bool movimientoValido(); //TODO Hay q redefinirla

    virtual ~Torre() noexcept override = default;

};

#endif // TORRE_HPP