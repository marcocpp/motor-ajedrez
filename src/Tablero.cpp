#include "Tablero.hpp"
#include "Ficha.hpp"
#include "Casilla.hpp"
#include "Peon.hpp"
#include "Torre.hpp"
#include "Caballo.hpp"
#include "Alfil.hpp"
#include "Reina.hpp"
#include "Rey.hpp"
#include <iostream>
#include <cstdlib>

Tablero::Tablero()
{

    // Set torres desde arriba a abajo
    for (int i = 0; i < 8; i++)
    {
        auto nuevaTorre = std::make_unique<Torre>(Color::NEGRO, 'R');
        m_casillas[7][i].setFicha(std::move(nuevaTorre));

        auto nuevaTorre2 = std::make_unique<Torre>(Color::BLANCO, 'R');
        m_casillas[0][i].setFicha(std::move(nuevaTorre2));
        i += 6;
    }

    // Set Caballos desde arriba a abajo
    for (int i = 1; i < 8; i++)
    {
        auto nuevoCaballo = std::make_unique<Caballo>(Color::NEGRO, 'N');
        m_casillas[7][i].setFicha(std::move(nuevoCaballo));

        auto nuevoCaballo2 = std::make_unique<Caballo>(Color::BLANCO, 'N');
        m_casillas[0][i].setFicha(std::move(nuevoCaballo2));
        i += 4;
    }

    // Set Alfil desde arriba abajo
    for (int i = 2; i < 8; i++)
    {
        auto nuevoAlfil = std::make_unique<Alfil>(Color::NEGRO, 'B');
        m_casillas[7][i].setFicha(std::move(nuevoAlfil));

        auto nuevoAlfil2 = std::make_unique<Alfil>(Color::BLANCO, 'B');
        m_casillas[0][i].setFicha(std::move(nuevoAlfil2));
        i += 2;
    }

    // Set Reina
    auto nuevoReina = std::make_unique<Reina>(Color::NEGRO, 'Q');
    m_casillas[7][3].setFicha(std::move(nuevoReina));

    auto nuevoReina2 = std::make_unique<Reina>(Color::BLANCO, 'Q');
    m_casillas[0][3].setFicha(std::move(nuevoReina2));

    // Set Rey
    auto nuevoRey = std::make_unique<Rey>(Color::NEGRO, 'K');
    m_casillas[7][4].setFicha(std::move(nuevoRey));

    auto nuevoRey2 = std::make_unique<Rey>(Color::BLANCO, 'K');
    m_casillas[0][4].setFicha(std::move(nuevoRey2));

    // Set peon desde arriba a abajo
    for (int i = 0; i < TAM; i++)
    {
        auto nuevoPeon = std::make_unique<Peon>(Color::NEGRO, 'P');
        m_casillas[6][i].setFicha(std::move(nuevoPeon));

        auto nuevoPeon2 = std::make_unique<Peon>(Color::BLANCO, 'P');
        m_casillas[1][i].setFicha(std::move(nuevoPeon2));
    }
}

void Tablero::dibujarTablero() {

    const std::string AZUL = "\033[34m";
    const std::string RESET = "\033[0m";

    std::cout << std::endl;

    for (int i = TAM - 1; i >= 0; i--)
    {
        std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
        std::cout << i + 1 << " |";
        for (int j = 0; j < TAM; j++)
        {
            if (m_casillas[i][j].getFicha())
            {
                if (m_casillas[i][j].getFicha()->getColor() == Color::NEGRO)
                {
                    std::cout << " " << AZUL << m_casillas[i][j].getFicha()->getIcono() << RESET << " |";
                }
                else
                {
                    std::cout << " " << m_casillas[i][j].getFicha()->getIcono() << " |";
                }
            }
            else
            {
                std::cout << "   |";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;

    std::cout << "    ";
    for (int c = 97; c < 97 + TAM; c++)
    {
        std::cout << char(c) << "   ";
    }
}

void Tablero::moverFicha(Coordenada origen, Coordenada destino) {
    // Guarda la ficha q va a mover: Primeo la quita de la casilla de origen con quitarFicha() y luego la asigna a fichaMovida
    std::unique_ptr<Ficha> fichaMovida = m_casillas[origen.fila][origen.col].quitarFicha();

    if (fichaMovida->getMovida() == false) {
        fichaMovida->setMovida(); // La ficha se ha movido por primera vez
    }

    // Asigna al destino la ficha movida
    m_casillas[destino.fila][destino.col].setFicha(std::move(fichaMovida));
}

Ficha* Tablero::getFichaCasilla(Coordenada casilla) const {
    return m_casillas[casilla.fila][casilla.col].getFicha();
}

// Mira casilla por casilla si el camino esta despejado, no hay ninguna ficha q lo bloquee
bool Tablero::caminoDespejado(Coordenada origen, Coordenada destino) {
    int filaActual = origen.fila;
    int colActual = origen.col;
    int pasoFila = destino.fila - origen.fila; // pasoFila = +1 (bajando), -1 (subiendo), 0 (no se mueve en fila)
    int pasoCol = destino.col - origen.col; // pasoCol = +1 (derecha), -1 (izquierda), 0 (no se mueve en columna)

    if (pasoFila >= 1) {
        pasoFila = 1;
    }
    else if (pasoFila <= -1) {
        pasoFila = -1;
    }
    else {
        pasoFila = 0;
    }

    if (pasoCol >= 1) {
        pasoCol = 1;
    }
    else if (pasoCol <= -1) {
        pasoCol = -1;
    }
    else {
        pasoCol = 0;
    }

    filaActual += pasoFila;
    colActual += pasoCol;

    while (filaActual != destino.fila || colActual != destino.col) {
        Ficha* nuevaFicha;

        nuevaFicha = m_casillas[filaActual][colActual].getFicha();

        if (nuevaFicha != nullptr) {
            return false; // Hay una ficha en la trayectoria, no se puede ejecutar el movimiento
        }

        filaActual += pasoFila;
        colActual += pasoCol;
    }

    return true;

}

bool Tablero::enroque(Coordenada origen, Coordenada destino, Ficha* ficha_org) {
    // TODO Comprobar si el rey pasa por una casilla atacada
    int fila_torre = (ficha_org->getColor() == Color::BLANCO) ? 0 : 7;
    int col_torre_izq = 0;
    int col_torre_der = 7;
    Coordenada torre_orig;
    Coordenada torre_dest;

    torre_orig.fila = fila_torre;
    torre_dest.fila = fila_torre;

    // La torre de la izquierda no se ha movido
    if (!m_casillas[fila_torre][col_torre_izq].getFicha()->getMovida() && origen.col - destino.col > 1) {
        torre_orig.col = col_torre_izq;
        torre_dest.col = col_torre_izq + 3;
        moverFicha(torre_orig, torre_dest);
        return true;
    }
    // La torre de la derecha no se ha movido
    else if (!m_casillas[fila_torre][col_torre_der].getFicha()->getMovida() && origen.col - destino.col < 1) {
        torre_orig.col = col_torre_der;
        torre_dest.col = col_torre_der - 2;
        moverFicha(torre_orig, torre_dest);
        return true;
    }
    return false;
}