#ifndef FICHA_HPP
#define FICHA_HPP

enum class Color {
    BLANCO,
    NEGRO
};

class Ficha {
public:
    Ficha(Color color);
    virtual ~Ficha() = default;

    Color getColor() const;
    virtual bool movimientoValido() = 0; //TODO Hay q poner los atributos

private:
    Color m_color;
};

#endif // FICHA_HPP