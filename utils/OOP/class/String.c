/*
** String.c for Zappy in /home/wyzlic_a/delivery/Zappy/String.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 14:38:17 2017 Dimitri Wyzlic
** Last update Mon Jun 05 14:38:17 2017 Dimitri Wyzlic
*/

#include "String.h"

static char	*val(String *this);
static String	*print(String *this);
static int	len(String *this);
static char	at(String *this, int at);
static String	*add(String *this, String *other);
static String	*epur(String *this, char to_delete);



String		*newString(char *str)
{
  void		*new;
  String	tmp;
  String	*out;

  tmp = initString(str);
  if ((new = calloc(1, sizeof(String))) == NULL)
    raise("Calloc String");
  if ((new = memcpy(new, &tmp, sizeof(String))) == NULL)
    raise("Memcpy String");
  out = (String *) new;

  return (out);
}

String		initString(char *str)
{
  String	out;

  out.len = &len;
  out.get = &val;
  out.at = &at;
  out.print = &print;
  out.add = &add;
  out.epur = &epur;

  out.__str = str;
  out.__len = strlen(str);

  return (out);
}

#include "implem/StringImplem1.c"
#include "implem/StringImplem2.c"