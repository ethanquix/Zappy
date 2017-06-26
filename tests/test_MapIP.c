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
//  MapCP		*map;
//  t_player	*a;
//  t_player	*b;
  t_vector	*vect;
//
  vect = new_vector();


  vect->delete(vect);
  free(vect);
//  a = new_player();
//  b = new_player();
//
//  a->name = newString("t_player A");
//  b->name = newString("t_player B");
//
//  map = newMapCP(10, NULL);
//  map->set(map, 12, a);
//  map->set(map, 13, b);
//
//  map->print(map, print);
//
//  map->erase(map, 13);
//  map->print(map, print);
//
//  map->delete(map);
//  a->delete(a);
//  b->delete(b);
  return (0);
}