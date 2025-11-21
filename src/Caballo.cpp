#include "Caballo.hpp"

Caballo::Caballo(Color color, char icono) : Ficha(color, icono) {

}


// El caballo se puede mover en forma de L desde la coordenada de origen
bool Caballo::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    // Si se pasa de alto o de largo
    if (abs(origen.fila - destino.fila) > 2 || abs(origen.col - destino.col) > 2) {
        return false;
    }
    else {
        // Se esta moviendo en diagonal
        if (abs(origen.fila - destino.fila) == abs(origen.col - destino.col)) {
            return false;
        }
        else {
            // Se mueven en horizontal o vertical
            if (abs(origen.fila - destino.fila) == 0 || abs(origen.col - destino.col) == 0) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}
