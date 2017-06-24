/*
** test_MapIP.c for Zappy in /home/wyzlic_a/delivery/Zappy/test_MapIP.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Sat Jun 24 21:40:37 2017 Dimitri Wyzlic
** Last update Sat Jun 24 21:40:37 2017 Dimitri Wyzlic
*/

#include <MapCP.h>
#include "Alfred.h"

void		print(PairCP *pair)
{
  printf("Id: %d name: %s\n", pair->key, pair->data->name->__str);
}

int		main()
{
  MapCP		*map;
  Player	*a;
  Player	*b;

  a = newPlayer();
  b = newPlayer();

  a->name = newString("Player A");
  b->name = newString("Player B");

  map = newMapCP(10, NULL);
  map->set(map, 12, a);
  map->set(map, 13, b);

  map->print(map, print);

  map->erase(map, 13);
  map->print(map, print);

  return (0);
}