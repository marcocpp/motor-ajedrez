#include "Peon.hpp"

Peon::Peon(Color color, char icono) : Ficha(color, icono) {}

bool Peon::movimientoValido() {
    return false;
}