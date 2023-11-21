#include "../include/gen_table.h"
#include "../include/play.h"
#include "../include/register_player.h"
#include "../include/show_menus.h"
#include <chrono>
#include <iostream>
#include <thread>

int main() {
  const char *LIMPIAR_PANTALLA = "\033[2J\033[1;1H"; // Limpiar la pantalla

  char opcion = 0;

  int puntaje_dorado = 0;

  std::vector<std::vector<Celda>> tabla;                  // tablero de juego
  std::vector<Jugador> jugadores = obtener_datos_de_jugadores(); // Datos de Jugadores no necesario
  std::vector<bool> opciones_cargadas(2, 0); // Opciones 1 y 2 cargadas para poder jugar

  while (1) {
    std::cout << LIMPIAR_PANTALLA;
    mostrar_menu_principal(opciones_cargadas[0], jugadores.size(), puntaje_dorado);
    std::cin >> opcion;
    if (opcion == '1') {
      tabla = generar_tabla(puntaje_dorado);
      opciones_cargadas[0] = 1;
    }
    if (opcion == '2') {

      if (jugadores.size() == 10)
        continue;

      std::cout << LIMPIAR_PANTALLA;
      std::string nombre, apellido, usuario;
      puts("*************** Registrar Usario **************");
      printf("\nNombre: ");
      std::cin >> nombre;
      printf("\nApellido: ");
      std::cin >> apellido;
      printf("\nNombre de Usario: ");
      std::cin >> usuario;
      crear_jugador(nombre, apellido, usuario, jugadores);
      opciones_cargadas[1] = 1;
    }
    if (opcion == '3') {
      std::cout << LIMPIAR_PANTALLA;
      mostrar_jugadores();
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    if (opcion == '4') {
      if (opciones_cargadas[0] && jugadores.size() >= 2) {
        jugar(tabla, puntaje_dorado);
      }
    }
    if (opcion == '5')
      break;
  }
  return 0;
}
