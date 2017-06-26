/*
** inventory.h for Zappy in /home/wyzlic_a/delivery/Zappy/inventory.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 22:07:41 2017 Dimitri Wyzlic
** Last update Sun Jun 25 16:28:33 2017 Doom
*/

#ifndef ZAPPY_INVENTORY_H
#define ZAPPY_INVENTORY_H

#include <time.h>
#include <stdlib.h>
#include "config.h"

#define MAX_MINERAL 7

typedef struct s_inv	Inventory;

typedef enum e_mineral	Mineral;

//TODO Norme
static char*	mineral_name[] =
  {
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    "food",
  };

typedef	enum	e_mineral
  {
    LINEMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    FOOD = 6
  }		t_mineral;

typedef struct	s_inv
{
  int		loot[7];
}		t_inv;

static void		init_inv(Inventory *inv)
{
  inv->loot[LINEMATE] = 0;
  inv->loot[DERAUMERE] = 0;
  inv->loot[SIBUR] = 0;
  inv->loot[MENDIANE] = 0;
  inv->loot[PHIRAS] = 0;
  inv->loot[THYSTAME] = 0;
  inv->loot[FOOD] = 0;
}

static void		random_inv(Inventory *inv)
{
  inv->loot[LINEMATE] = rand() % LINEMATE_RARITY;
  inv->loot[DERAUMERE] = rand() % DERAUMERE_RARITY;
  inv->loot[SIBUR] = rand() % SIBUR_RARITY;
  inv->loot[MENDIANE] = rand() % MENDIANE_RARITY;
  inv->loot[PHIRAS] = rand() % PHIRAS_RARITY;
  inv->loot[THYSTAME] = rand() % THYSTAME_RARITY;
  inv->loot[FOOD] = rand() % FOOD_RARITY;
}

#endif //ZAPPY_INVENTORY_H
