#ifndef ALFIL_HPP
#define ALFIL_HPP

#include "Ficha.hpp"


class Alfil : public Ficha {
public:
    Alfil(Color color, char icono);
    bool movimientoValido(Coordenada origen, Coordenada destino); //TODO Hay q redefinirla

    virtual ~Alfil() noexcept override = default;
};

#endif // ALFIL_HPP