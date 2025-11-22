#include "Peon.hpp"
#include <math.h>

Peon::Peon(Color color, char icono) : Ficha(color, icono) {}


// Si el peon aun no se ha movido, se puede mover 1 o 2 hacia delante
// Se puede mover siempre en diagonal hacia delante si y solo sí, hay una ficha contraria
// Si hay una ficha justo enfrente, el peon no se puede mover hacia delante
// No se puede mover hacia atrás
bool Peon::movimientoValido(Coordenada origen, Coordenada destino, bool esCaptura) {
    int direccion = (this->getColor() == Color::BLANCO) ? 1 : -1; // Si es color blanco, avanza en fila +1, si es negro, avanza en fila -1
    int avanceFila = destino.fila - origen.fila;
    int avanceFilaAbs = abs(avanceFila);
    int avanceCol = destino.col - origen.col;
    int avanceColAbs = abs(avanceCol);

    // Movimiento vertical y no captura
    if (avanceCol == 0 && !esCaptura) {
        // Si es la primera vez que se mueve: avanza 1 o 2
        if (!this->getMovida() && avanceFila == 2 * direccion) {
            return true;
        }
        // Avanza 1, da igual si es la primera vez o no
        if (avanceFila == direccion) {
            return true;
        }
    }
    else if (avanceFilaAbs == 1 && avanceColAbs == 1 && esCaptura) { // Si es diagonal y es captura
        if (avanceFila == direccion) { // Comprueba q avance en la direccion q le corresponde, es decir, hacia adelante dependiendo del color
            return true;
        }
        return false; // Esta intentando capturar hacia atras
    }
    return false; // Cual quiera otro movimiento es invalido, por ejemplo, avanza en vertical y es captura

    // Falta implementar la captura al paso
    // Promocion de peon cuando la llega al final del tablero
}