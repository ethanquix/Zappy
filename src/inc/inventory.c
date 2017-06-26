/*
** inventory.c for Zappy in /home/wyzlic_a/delivery/Zappy/inventory.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 26 14:11:11 2017 Dimitri Wyzlic
** Last update Mon Jun 26 14:11:11 2017 Dimitri Wyzlic
*/

#include "inventory.h"

void		init_inv(t_inv *inv)
{
  inv->loot[LINEMATE] = 0;
  inv->loot[DERAUMERE] = 0;
  inv->loot[SIBUR] = 0;
  inv->loot[MENDIANE] = 0;
  inv->loot[PHIRAS] = 0;
  inv->loot[THYSTAME] = 0;
  inv->loot[FOOD] = 0;
}

void		random_inv(t_inv *inv)
{
  inv->loot[LINEMATE] = rand() % LINEMATE_RARITY;
  inv->loot[DERAUMERE] = rand() % DERAUMERE_RARITY;
  inv->loot[SIBUR] = rand() % SIBUR_RARITY;
  inv->loot[MENDIANE] = rand() % MENDIANE_RARITY;
  inv->loot[PHIRAS] = rand() % PHIRAS_RARITY;
  inv->loot[THYSTAME] = rand() % THYSTAME_RARITY;
  inv->loot[FOOD] = rand() % FOOD_RARITY;
}