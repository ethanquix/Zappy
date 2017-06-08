/*
** inventory.h for Zappy in /home/wyzlic_a/delivery/Zappy/inventory.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 22:07:41 2017 Dimitri Wyzlic
** Last update Wed Jun 07 22:07:41 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_INVENTORY_H
#define ZAPPY_INVENTORY_H

typedef struct s_inv	Inventory;

typedef enum e_mineral	Mineral;

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
  char		loot[7];
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

#endif //ZAPPY_INVENTORY_H
