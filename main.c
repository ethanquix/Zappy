#include <stdio.h>

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

  t->to_str(t);
}


int		zappy()
{
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

//
//
//  printf("String Pointer!\nsize= %d -> __str= %s\n", str->len(str),
//	 str->get(str));
//  printf("String Local!\nsize= %d -> __str= %s\n", test.len(&test),
//	 test.get(&test));
  return 0;
}