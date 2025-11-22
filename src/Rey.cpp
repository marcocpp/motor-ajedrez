#include "Rey.hpp"

Rey::Rey(Color color, char icono) : Ficha(color, icono) {}

bool Rey::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    int delta_fila = abs(origen.fila - destino.fila);
    int delta_col = abs(origen.col - destino.col);

    if (delta_fila <= 1 && delta_col <= 1) {
        return true;
    }

    if (!this->getMovida() && delta_col == 2 && delta_fila == 0) {
        return true; // Posible enroque
    }

    return false;
}
