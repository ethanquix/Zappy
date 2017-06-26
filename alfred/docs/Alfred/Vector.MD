Create:

- `Vector		init_vector()`
- `Vector		*new_vector()`

Method:

- `int		len(Vector *this)`
- `Vector	*add(Vector *this, void *obj)`
- `Vector	*set(String *this, int pos, void * obj)`
- `void		*get(String *this, int pos)`
- `Vector	*pop(Vector *this, int pos)`
- `Vector	*print(Vector *this, void (*_func)(void *))`

Macros:

- `VGET(var, vector, pos)` -> var = ((typeof(var))(vect)->get(vect, pos))
- `VGETNP(var, vector, pos)` -> var = ((typeof(var))(vect).get(&vect, pos))


Example:
```
#include "Vector.h";

void myPrint(void *c)
{
  String *t;

  t = (String *)c;
  t->print(t);
}

void		vector_sample()
{
  Vector	*vector;
  String	test;
  String	*str;

  vector = new_vector();
  
  test = initString("I am a Local String");
  str = newString("I am a Pointer String");


  vector->add(vector, &test);
  vector->add(vector, str);

  printf("%s\n", ((String *)vector->get(vector, 1))->__str);
  vector->print(vector, &myPrint);
}
```
