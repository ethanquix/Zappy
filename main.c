/*
** main.c for Zappy in /home/wyzlic_a/delivery/Zappy/main.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include <stdio.h>

#include "MapCI.h"
#include "Alfred.h"
#include "Vector.h"
#include "String.h"

THE_BEST
ZAPPY_EVER


int main<:ZAPPY:>;


void a(void *c)
{
  String *t;

  t = (String *)c;

  t->print(t);
}


int		zappy()
{
  MapCI		*map;

  map = newMapCI(100, -1);

  printf("Test: %d\n", map->set(map, "toto", 1)->get(map, "toto"));

  String	test;
  String	*str;
  Vector	*vector;

  test = initString("I am a Local String");
  str = newString("I am a Pointer String");

  vector = newVector();

  vector->add(vector, &test);
  vector->add(vector, str);

  printf("%s\n", ((String *)vector->get(vector, 1))->__str);
  vector->print(vector, &a);



  printf("String Pointer!\nsize= %d -> __str= %s\n", str->len(str),
	 str->get(str));
  printf("String Local!\nsize= %d -> __str= %s\n", test.len(&test),
	 test.get(&test));
  return 0;
}