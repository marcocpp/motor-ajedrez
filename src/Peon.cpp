#include "Peon.hpp"

Peon::Peon(Color color, char icono) : Ficha(color, icono) {}


// Si el peon aun no se ha movido, se puede mover 1 o 2 hacia delante
// Se puede mover siempre en diagonal hacia delante si y solo sí, hay una ficha contraria
// Si hay una ficha justo enfrente, el peon no se puede mover hacia delante
// No se puede mover hacia atrás
bool Peon::movimientoValido(Coordenada origen, Coordenada destino) {
    //  Movimiento para peon BLANCO
    if (this->getColor() == Color::BLANCO) {
        // Si no se ha movido aun y su destino-origen es 1 o 2, es decir se mueve 1 o 2 hacia delante, es valido
        if (origen.fila == 1 && ((destino.fila - origen.fila) == 1 || (destino.fila - origen.fila) == 2)) {
            // Si no se ha movido de columna
            if (origen.col == destino.col) {
                // TODO Si delante hay otra ficha, no puede seguir hacia delante
                return true;
            }
            else {
                // TODO Se ha movido en oblicuo, asi q comprobar si hay una ficha q puede comer
                return false;
            }

        }
        else if ((destino.fila - origen.fila) == 1) { // Ya se ha movido., solo se puede mover una hacia delante
            if (origen.col == destino.col) {
                // TODO Si delante hay otra ficha, no puede seguir hacia delante
                return true;
            }
            else {
                // TODO Se ha movido en oblicuo, asi q comprobar si hay una ficha q puede comer
                return false;
            }
        }
        else {
            // Se ha movido mas de 1 posicion, o mas de 2 en el caso de q no se haya movido, o bien se ha movido en oblicuo y no podia
            return false;
        }
    }
    else { // Movimiento para peon NEGRO
        if (origen.fila == 6 && ((origen.fila - destino.fila) == 1 || (origen.fila - destino.fila) == 2)) {
            if (origen.col == destino.col) {
                // TODO Si delante hay otra ficha, no puede seguir hacia delante
                return true;
            }
            else {
                // TODO Se ha movido en oblicuo, asi q comprobar si hay una ficha q puede comer
                return false;
            }

        }
        else if ((origen.fila - destino.fila) == 1) {
            if (origen.col == destino.col) {
                // TODO Si delante hay otra ficha, no puede seguir hacia delante
                return true;
            }
            else {
                // TODO Se ha movido en oblicuo, asi q comprobar si hay una ficha q puede comer
                return false;
            }
        }
        else {
            return false;

        }
    }
}