Create:

- `String		initString(char *str)`
- `String		*newString(char *str)`

Method:

- `char		*val(String *this)`
- `String	*print(String *this)`
- `int		len(String *this)`
- `char		at(String *this, int pos)`
- `String	*add(String *this, String *other)`
- `String	*epur(String *this, char to_delete)`

Example:
```
#include "String.h";

void		string_sample()
{
  String	test;
  String	*str;

  test = initString("I am a Local String");
  str = newString("I am a Pointer String");

  printf("String Pointer!\nsize= %d -> __str= %s\n", str->len(str), str->get(str));
  printf("String Local!\nsize= %d -> __str= %s\n", test.len(&test), test.get(&test));
  return 0;
}
```
