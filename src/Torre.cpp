#include "Torre.hpp"

Torre::Torre(Color color, char icono) : Ficha(color, icono) {

}

// La torre se mueve en horizontal/vertical
bool Torre::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    // Se mueven en horizontal o vertical
    if (abs(origen.fila - destino.fila) == 0 || abs(origen.col - destino.col) == 0) {
        return true;
    }
    return false;
}
