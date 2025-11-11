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
        Ficha *nuevaTorre = new Torre(Color::NEGRO, 'R');
        m_casillas[7][i].setFicha(nuevaTorre);
        m_fichasTablero.push_back(nuevaTorre);

        Ficha *nuevaTorre2 = new Torre(Color::BLANCO, 'R');
        m_casillas[0][i].setFicha(nuevaTorre2);
        m_fichasTablero.push_back(nuevaTorre2);
        i += 6;
    }

    // Set Caballos desde arriba a abajo
    for (int i = 1; i < 8; i++)
    {
        Ficha *nuevoCaballo = new Caballo(Color::NEGRO, 'N');
        m_casillas[7][i].setFicha(nuevoCaballo);
        m_fichasTablero.push_back(nuevoCaballo);

        Ficha *nuevoCaballo2 = new Caballo(Color::BLANCO, 'N');
        m_casillas[0][i].setFicha(nuevoCaballo2);
        m_fichasTablero.push_back(nuevoCaballo2);
        i += 4;
    }

    // Set Alfil desde arriba abajo
    for (int i = 2; i < 8; i++)
    {
        Ficha *nuevoAlfil = new Alfil(Color::NEGRO, 'B');
        m_casillas[7][i].setFicha(nuevoAlfil);
        m_fichasTablero.push_back(nuevoAlfil);

        Ficha *nuevoAlfil2 = new Alfil(Color::BLANCO, 'B');
        m_casillas[0][i].setFicha(nuevoAlfil2);
        m_fichasTablero.push_back(nuevoAlfil2);
        i += 2;
    }

    // Set Reina
    Ficha *nuevoReina = new Reina(Color::NEGRO, 'Q');
    m_casillas[7][3].setFicha(nuevoReina);
    m_fichasTablero.push_back(nuevoReina);

    Ficha *nuevoReina2 = new Reina(Color::BLANCO, 'Q');
    m_casillas[0][3].setFicha(nuevoReina2);
    m_fichasTablero.push_back(nuevoReina2);

    // Set Rey
    Ficha *nuevoRey = new Rey(Color::NEGRO, 'K');
    m_casillas[7][4].setFicha(nuevoRey);
    m_fichasTablero.push_back(nuevoRey);

    Ficha *nuevoRey2 = new Rey(Color::BLANCO, 'K');
    m_casillas[0][4].setFicha(nuevoRey2);
    m_fichasTablero.push_back(nuevoRey2);

    // Set peon desde arriba a abajo
    for (int i = 0; i < TAM; i++)
    {
        Ficha *nuevoPeon = new Peon(Color::NEGRO, 'P');
        m_casillas[6][i].setFicha(nuevoPeon);
        m_fichasTablero.push_back(nuevoPeon); // Guarda las fichas para borrarlas despues

        Ficha *nuevoPeon2 = new Peon(Color::BLANCO, 'P');
        m_casillas[1][i].setFicha(nuevoPeon2);
        m_fichasTablero.push_back(nuevoPeon2);
    }
}

void Tablero::dibujarTablero()
{

    const std::string AZUL = "\033[34m";
    const std::string RESET = "\033[0m";

    std::cout << std::endl;

    for (int i = TAM - 1; i >= 0; i--)
    {
        std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
        std::cout << i + 1 << " |";
        for (int j = 0; j < TAM; j++)
        {
            if (m_casillas[i][j].getFicha() != nullptr)
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
    { // TODO ARREGLAR
        std::cout << char(c) << "   ";
    }

    std::cout << "\nBlancas: Color blanco" << std::endl;
    std::cout << "Negras: Color Azul" << std::endl;
}