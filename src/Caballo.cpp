#include "Caballo.hpp"

Caballo::Caballo(Color color, char icono) : Ficha(color, icono) {

}

bool Caballo::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    return false;
}
