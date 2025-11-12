#include "Rey.hpp"

Rey::Rey(Color color, char icono) : Ficha(color, icono) {}

bool Rey::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    return false;
}
