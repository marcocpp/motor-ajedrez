#include <iostream>

#include "Partida.hpp"

int main(int, char**) {

    std::string nombre_j1 = "usr1";
    std::string nombre_j2 = "usr2";

    Partida p1(nombre_j1, nombre_j2);

    p1.iniciarPartida();

    return 0;
}

