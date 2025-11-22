#include "Reina.hpp"

Reina::Reina(Color color, char icono) : Ficha(color, icono) {}

// Su movimiento es como la suma del alfil y la torre
bool Reina::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    if (abs(origen.fila - destino.fila) == abs(origen.col - destino.col)) {
        return true;
    }
    else if (abs(origen.fila - destino.fila) == 0 || abs(origen.col - destino.col) == 0) {
        return true;
    }
    return false;
}
