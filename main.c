/*
** main.c for Zappy in /home/wyzlic_a/delivery/Zappy/main.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include "MapCI.h"
#include "Alfred.h"


THE_BEST
ZAPPY_EVER


int main<:ZAPPY:>;


/*
** TODO Zappy in the zappy() func
** :)
*/
int		zappy()
{
  MapCI		*map;
  PairCI	*pair;


  map = newMapCI(1000, -1);

  map->set(map, "toto", 1);
  map->set(map, "salut", 2);
  map->set(map, "je", 3);
  map->set(map, "suis", 4);
  map->set(map, "un", 5);
  map->set(map, "dimitri", 6);

  printf("Test: %d\n", map->get(map, "toto"));

  map->start_loop(map);
  while ((pair = map->loop(map)) NOT NULL)
    printf("key: %s data: %d\n", pair->key, pair->data);

  return 0;
}