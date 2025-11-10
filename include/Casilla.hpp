#ifndef CASILLA_HPP
#define CASILLA_HPP

class Ficha;

class Casilla {
public:
    Casilla();

    void setFicha(Ficha* ficha);
    Ficha* getFicha();

private:
    Ficha* m_fichaActual = nullptr; // Si ficha = nullptr, la casilla está vacia
};

#endif // CASILLA_HPP