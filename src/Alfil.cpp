#include "Alfil.hpp"

Alfil::Alfil(Color color, char icono) : Ficha(color, icono) {}

// El alfil se mueve en diagonal
bool Alfil::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    // Se esta moviendo en diagonal
    if (abs(origen.fila - destino.fila) == abs(origen.col - destino.col)) {
        return true;
    }
    else {
        return false;
    }
}
