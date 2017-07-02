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
    UNKNOW = -1,
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
  int		loot[MAX_MINERAL];
}		t_inv;

void		init_inv(t_inv *inv);
void		random_inv(t_inv *inv);

#endif //ZAPPY_INVENTORY_H
