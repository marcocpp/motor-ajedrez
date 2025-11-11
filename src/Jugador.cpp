#include "Jugador.hpp"
#include <limits>

Jugador::Jugador(Color color, std::string nombre) : m_color(color), m_nombre(nombre) {

}

Color Jugador::getColor() const {
    return m_color;
}

std::string Jugador::getNombre() const {
    return m_nombre;
}

Coordenada Jugador::solicitarCoordenada(std::string texto) {
    std::string input = "";
    bool inputValido = false;

    while (!inputValido) {
        std::cout << m_nombre << ", " << texto;
        std::cin >> input;

        if (input.length() != 2) {
            std::cerr << "ERROR: La coordenada debe tener dos caracteres (ej: 'e2').\n";
        }
        else if (input[0] < 'a' || input[0] > 'h') {
            std::cerr << "ERROR: La coordenada intrucida debe de estar entre 'a' y 'h'.\n";
        }
        else if (input[1] < '1' || input[1]> '8') {
            std::cerr << "ERROR: La cordenada introducida debe de estar entre '1' y '8'.\n";
        }
        else {
            inputValido = true;
        }

        // Limpia el buffer de std::cin por si el usuario escribió "hola mundo"
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // 'e' - 'a' = 4
    int col = input[0] - 'a';

    // '2' - '1' = 1
    int fila = input[1] - '1';


    return Coordenada{ fila, col };

}