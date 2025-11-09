#include "Tablero.hpp"
#include "Ficha.hpp"
#include "Casilla.hpp"
#include "Peon.hpp"

Tablero::Tablero() {

    // TODO terminar el constructor
    // Set peon desde arriba a abajo
    for (int i = 0; i < TAM; i++) {
        Ficha* nuevoPeon = new Peon(Color::BLANCO);
        m_casillas[0][i].setFicha(nuevoPeon);
        m_fichasTablero.push_back(nuevoPeon); // Guarda las fichas para borrarlas despues
    }

}