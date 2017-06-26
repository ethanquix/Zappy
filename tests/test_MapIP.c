/*
** test_MapIP.c for Zappy in /home/wyzlic_a/delivery/Zappy/test_MapIP.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Sat Jun 24 21:40:37 2017 Dimitri Wyzlic
** Last update Sat Jun 24 21:40:37 2017 Dimitri Wyzlic
*/

#include "MapCP.h"
#include "Vector.h"
#include "Alfred.h"

void		print(PairCP *pair)
{
  printf("Id: %d name: %s\n", pair->key, pair->data->name->__str);
}

int		main()
{
  MapCP		*map;
  t_player	*a;
  t_player	*b;

  a = new_player();
  b = new_player();
  a->name = new_string("t_player A");
  b->name = new_string("t_player B");
  map = newMapCP(10, NULL);
  map->set(map, 12, a);
  map->set(map, 13, b);
  map->print(map, print);
  map->erase(map, 13);
  map->print(map, print);
  return (0);
}