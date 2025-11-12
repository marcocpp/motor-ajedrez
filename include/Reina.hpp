#ifndef REINA_HPP
#define REINA_HPP

#include "Ficha.hpp"


class Reina : public Ficha {
public:
    Reina(Color color, char icono);
    bool movimientoValido(Coordenada origen, Coordenada destino); //TODO Hay q redefinirla

    virtual ~Reina() noexcept override = default;

};

#endif // REINA_HPP
