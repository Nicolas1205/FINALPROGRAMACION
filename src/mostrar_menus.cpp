#include "../include/mostrar_menus.h"
#include "../include/elegir_jugador.h"
#include "../include/generar_tabla.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

void mostrar_jugador_ganador(Jugador *jugador_ganador) {
  std::cout << "******** RESULTADOS DE LA PARTIDA **************\n";
  std::cout << "Jugador: " << jugador_ganador->usuario << " ha ganado!!!\n\n"
            << "Nombre Completo: " << jugador_ganador->nombre << " " << jugador_ganador->apellido
            << '\n';
  std::cout << "Puntaje Total: " << jugador_ganador->puntaje_total << '\n';
}

void mostrar_menu_principal(bool tabla_creada, size_t cantidad_jugadores,
                            int &puntaje_dorado) {

  std::cout << "************* PRINCIPAL **************** \n"
               "1- Generar tablero  ";

  if (tabla_creada) {
    std::cout << "(TABLERO GENERADO) Puntaje Dorado: " << puntaje_dorado;
  }

  std::cout << "\n2- Registrar jugadores ";

  if (cantidad_jugadores) {
    std::cout << " (Existen Jugadores Registrados) ";
  }
  if (cantidad_jugadores >= 2) {
    std::cout << cantidad_jugadores;
  } else {
    std::cout << " (se necesitan 2 o mas jugadores, ahora mismo: "
              << cantidad_jugadores;
  }

  if (cantidad_jugadores == 10)
    std::cout << " (No se pueden registar mas jugadores) ";

  std::cout << "\n3- Listar jugadores \n"
               "4- Jugar \n"
               "5- Salir \n"
               "******************************************* \n"
               "Elija una opcion: ";
}

void mostrar_menu_de_juego(std::vector<Jugador> &jugadores) {
  std::cout << "\n********* Comienza la aventura ***********\n";

  std::cout << "1- Seleccionar jugadores ";

  if (jugadores.size())
    std::cout << " (Jugador 1: " << jugadores[0].usuario
              << " Jugador 2: " << jugadores[1].usuario << ")\n";
  else
    std::cout << " (No hay jugadores Seleccionados)\n";

  std::cout << "2- Lanzamiento de dados\n"
               "3- Salir\n"
               "******************************************\n"
               "Elija una opcion: ";
}

void mostrar_resultado_de_jugador(Jugador &jugador, std::pair<int, int> dados,
                                  Celda &celda, int puntaje) {

  std::cout << "\n\nTurno de jugador: " << jugador.usuario << '\n';
  std::cout << "Lanzando dados...\n";
  std::cout << "Dado 1: " << dados.first << " - Dado 2: " << dados.second
            << '\n';
  std::cout << "Numero Encontrado: " << celda.numero_celda;

  if (celda.es_primo) {
    std::cout << " (primo) ";
  }
  if (celda.es_capicua) {
    std::cout << " (capicua) ";
  }
  if (celda.es_amigo) {
    std::cout << " (amigo) 1 turno ";
  }
  if (celda.es_perfecto) {
    std::cout << " (perfecto) 2 turnos ";
  }
  if (celda.es_diagonal) {
    std::cout << " (diagonal) ";
  }
  std::cout << "\nPuntaje : " << puntaje << '\n';
  std::cout << "Puntaje Total: " << jugador.puntaje_total << '\n';
}
