#include "../include/show_menus.h"
#include "../include/chose_player.h"
#include "../include/gen_table.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

void mostrar_jugador_ganador(Jugador *winner) {
  std::cout << "******** RESULTADOS DE LA PARTIDA **************\n";
  std::cout << "Jugador: " << winner->usuario << " ha ganado!!!\n\n"
            << "Nombre Completo: " << winner->nombre<< " " << winner->apellido
            << '\n';
  std::cout << "Puntaje Total: " << winner->puntaje_total << '\n';
}

void mostrar_menu_principal(bool table_created, size_t players_sz, int &golden_score) {

  printf("************* PRINCIPAL **************** \n"
         "1- Generar tablero  ");

  if (table_created)
    printf("(TABLERO GENERADO) Puntaje Dorado: %d", golden_score);

  printf("\n2- Registrar jugadores ");

  if (players_sz)
    printf("(Existen Jugadores Registrados)");
  if (players_sz >= 2)
    printf(" %zu ", players_sz);
  else
    printf(" se necesitan 2 o mas jugadores, ahora mismo %zu", players_sz);
  if (players_sz == 10)
    printf(" (No se pueden registar mas jugadores) ");

  printf("\n3- Listar jugadores \n"
         "4- Jugar \n"
         "5- Salir \n"
         "******************************************* \n"
         "Elija una opcion: ");
}

void mostrar_menu_de_juego(std::vector<Jugador> &jugadores) {
  printf("\n********* Comienza la aventura ***********\n");

  printf("1- Seleccionar jugadores ");

  if (jugadores.size())
    std::cout << " (Jugador 1: " << jugadores[0].usuario
              << " Jugador 2: " << jugadores[1].usuario << ")\n";
  else
    printf(" (No hay jugadores Seleccionados)\n");

  printf("2- Lanzamiento de dados\n"
         "3- Salir\n"
         "******************************************\n"
         "Elija una opcion: ");
}

void mostrar_resultado_de_jugador(Jugador &jugador, std::pair<int, int> dados,
                         Celda &celda, int puntaje) {

  std::cout << "\n\nTurno de jugador: " << jugador.usuario << '\n';
  std::cout << "Lanzando dados...\n";
  std::cout << "Dado 1: " << dados.first << " - Dado 2: " << dados.second
            << '\n';
  std::cout << "Numero Encontrado: " << celda.numero_celda;

  if(celda.is_prime) {
    std::cout<<" (primo) ";
  }
  if(celda.is_palindrome) {
    std::cout<<" (capicua) ";
  }
  if(celda.is_friend) {
    std::cout<<" (amigo) 1 turno ";
  }
  if(celda.is_perfect) {
    std::cout<<" (perfecto) 2 turnos ";
  }
  if(celda.is_diagonal) {
    std::cout<<" (diagonal) ";
  }
  std::cout << "\nPuntaje : " << puntaje << '\n';
  std::cout<<  "Puntaje Total: " << jugador.puntaje_total << '\n';
}
