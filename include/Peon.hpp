#ifndef PEON_HPP
#define PEON_HPP

#include "Ficha.hpp"

class Peon : public Ficha {
public:
    Peon(Color color, char icono);
    bool movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura); // TODO Hay q redefinirla

    virtual ~Peon() noexcept override = default;
};

#endif // PEON_HPP
