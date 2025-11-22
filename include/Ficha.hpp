#ifndef FICHA_HPP
#define FICHA_HPP

#include "TiposJuego.hpp"

class Ficha {
public:
    Ficha(Color color, char icono);
    virtual ~Ficha() noexcept = default;

    Color getColor() const;
    virtual bool movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) = 0; // TODO Hay q poner los atributos

    char getIcono() const;
    bool getMovida() const;
    void setMovida();

private:
    Color m_color;
    char m_icono = ' ';
    bool m_haSidoMovida = false;
};

#endif // FICHA_HPP
