#include "Partida.hpp"

Partida::Partida(std::string nombre_j1, std::string nombre_j2) : m_tablero(), m_jugador1(Color::BLANCO, nombre_j1), m_jugador2(Color::NEGRO, nombre_j2)
{
    m_jugadorActual = &m_jugador1; // Empieza el jugador 1
}

std::pair<bool, bool> Partida::validarMovimiento(Coordenada origen, Coordenada destino, Ficha* ficha_org, Ficha* ficha_dest)
{
    bool esCaptura = false;

    // Validar si en origen hay una ficha
    if (ficha_org == nullptr) {
        return { false,false }; // No hay ficha en esa casilla
    }

    // Validar turno (que no intente mover una ficha q no es tuya. que el blanco no mueva una negra)
    if (ficha_org->getColor() != m_jugadorActual->getColor()) {
        return { false,false }; // Esta intentando mover una ficha q no es suya
    }

    // Validar autocaptura (que el usuario no capture una ficha propia)
    if (ficha_dest != nullptr) {
        esCaptura = true; // Se va a comer una ficha
        if (ficha_dest->getColor() == ficha_org->getColor()) {
            return { false,false }; // Autocaptura!
        }
    }

    // Si hay una ficha, identificar cual es para ver q movimiento puede hacer y verificar si esa ficha puede hacer ese mov
    if (!ficha_org->movimientoValido(origen, destino, esCaptura)) {
        return { false,false }; // Movimiento de ficha invalido
    }

    // Validar si no hay ninguna ficha propia en la trayectoria q realiza q le impida avanzar
    if (ficha_org->getIcono() != 'N') { // El caballo si puede saltar fichas
        if (!m_tablero.caminoDespejado(origen, destino)) {
            return { false,false }; // Hay una ficha en la trayectoria q impide el movimiento
        }
    }

    // Validar si es jaque (No puedes hacer ningún movimiento que deje a tu propio rey en jaque)

    // Validar enroque:
    // 1- ni el rey ni la torre involucrada deben haberse movido antes: OK 
    // 2- las casillas entre ellos deben estar desocupadas: OK (comprobado antes)
    // 3- el rey no puede estar en jaque 
    // 4- no puede pasar ni terminar en una casilla atacada por el rival. 

    // Comprobar enroque
    if (!ficha_org->getMovida() && ficha_org->getIcono() == 'K' && abs(origen.col - destino.col) == 2 && abs(origen.fila - destino.fila) == 0) {
        if (m_tablero.enroque(origen, destino, ficha_org)) {
            // No se ha movido la torre
            return { true, true };
        }
        return { false, false };
    }

    return { true,false }; // Movimiento de ficha valido

}

void Partida::iniciarPartida() {
    limpiarPantalla();
    m_juegoEnCurso = true;
    std::cout << m_jugadorActual->getNombre() << " empezara el turno (Blancas)" << std::endl;

    while (m_juegoEnCurso) {

        m_tablero.dibujarTablero();

        std::cout << "\nTurno de: " << m_jugadorActual->getNombre() << std::endl;

        // Pedimos el origen
        Coordenada origen = m_jugadorActual->solicitarCoordenada("introduce la casilla de ORIGEN (ej: e2): ");

        // Pedimos el destino
        Coordenada destino = m_jugadorActual->solicitarCoordenada("introduce la casilla de DESTINO (ej: e4): ");

        Ficha* ficha_org = m_tablero.getFichaCasilla(origen);
        Ficha* ficha_dest = m_tablero.getFichaCasilla(destino);

        std::pair<bool, bool> resultado = validarMovimiento(origen, destino, ficha_org, ficha_dest);

        bool esValido = resultado.first;
        bool esEnroque = resultado.second;

        // Validamos el movimiento
        if (esValido)
        {
            if (esEnroque) {
                m_tablero.ejecutarEnroque(origen, destino, ficha_org);
            }
            else {
                m_tablero.moverFicha(origen, destino);
            }

            // Cambia de jugador
            //m_jugadorActual = (m_jugadorActual == &m_jugador1) ? &m_jugador2 : &m_jugador1;
        }
        else
        {
            std::cout << "Movimiento invalido! Intentalo de nuevo.\nEnter para contiunar..." << std::endl;
            std::cin.get();
        }

        limpiarPantalla();

        m_juegoEnCurso = true; // Quitar, aqui la condicion seria tablas, jaque-mate, o rendicion

    }
}
