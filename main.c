#include <stdio.h>

#include "Alfred.h"
#include "Vector.h"
#include "String.h"

THE_BEST
ZAPPY_EVER


int main[ZAPPY];


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


  printf("String Pointer!\nsize= %d -> __str= %s\n", str->len(str),
	 str->get(str));
  printf("String Local!\nsize= %d -> __str= %s\n", test.len(&test),
	 test.get(&test));
  return 0;
}