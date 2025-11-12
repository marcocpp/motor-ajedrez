#ifndef REY_HPP
#define REY_HPP

#include "Ficha.hpp"


class Rey : public Ficha {
public:
    Rey(Color color, char icono);
    bool movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura); //TODO Hay q redefinirla

    virtual ~Rey() noexcept override = default;

};

#endif // REY_HPP
