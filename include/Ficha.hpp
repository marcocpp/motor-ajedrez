#ifndef FICHA_HPP
#define FICHA_HPP

#include "TiposJuego.hpp"

class Ficha {
public:
    Ficha(Color color, char icono);
    virtual ~Ficha() noexcept = default;

    Color getColor() const;
    virtual bool movimientoValido() = 0; // TODO Hay q poner los atributos

    char getIcono() const;

private:
    Color m_color;
    char m_icono = ' ';
};

#endif // FICHA_HPP