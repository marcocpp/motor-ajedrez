#include "Partida.hpp"


Partida::Partida(std::string nombre_j1, std::string nombre_j2) : m_tablero(), m_jugador1(Color::BLANCO, nombre_j1), m_jugador2(Color::NEGRO, nombre_j2) {
    m_jugadorActual = &m_jugador1; // Empieza el jugador 1
}

bool Partida::validarMovimiento(Coordenada origen, Coordenada destino) {
    // Validar si en origen hay una ficha
    // Si hay una ficha, identificar cual es para ver q movimiento puede hacer
    // Verificar destino para ver si ese tipo de ficha puede moverse a ese sitio
    // Validar si es jaque (No puedes hacer ningún movimiento que deje a tu propio rey en jaque)
    // Validar turno (que no intente mover una ficha q no es tuya. que el blanco no mueva una negra)
    // Validar autocaptura (que el usuario no capture una ficha propia)
    return true;
}

void Partida::iniciarPartida() {
    m_juegoEnCurso = true;
    std::cout << m_jugadorActual->getNombre() << " empezara el turno (Blancas)" << std::endl;

    m_tablero.dibujarTablero();

    while (m_juegoEnCurso) {
        std::cout << "\nTurno de: " << m_jugadorActual->getNombre() << std::endl;

        // Pedimos el origen
        Coordenada origen = m_jugadorActual->solicitarCoordenada("introduce la casilla de ORIGEN (ej: e2): ");

        // Pedimos el destino
        Coordenada destino = m_jugadorActual->solicitarCoordenada("introduce la casilla de DESTINO (ej: e4): ");

        // Validamos el movimiento
        if (validarMovimiento(origen, destino)) {
            m_tablero.moverFicha(origen, destino);

            // Cambia de jugador
            m_jugadorActual = (m_jugadorActual == &m_jugador1) ? &m_jugador2 : &m_jugador1;
        }
        else {
            std::cout << "¡Movimiento inválido! Inténtalo de nuevo." << std::endl;
        }

        m_juegoEnCurso = false; // Quitar, aqui la condicion seria tablas, jaque-mate, o rendicion
    }
}