#ifndef ALFIL_HPP
#define ALFIL_HPP

#include "Ficha.hpp"


class Alfil : public Ficha {
public:
    Alfil(Color color, char icono);
    bool movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura); //TODO Hay q redefinirla

    virtual ~Alfil() noexcept override = default;
};

#endif // ALFIL_HPP
