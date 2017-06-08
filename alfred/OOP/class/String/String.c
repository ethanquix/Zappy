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

static char	*val(THIS);
static String	*print(THIS);
static int	len(THIS);
static char	at(THIS, int at);
static String	*add(THIS, String *other);
static String	*epur(THIS, char to_delete);



String		*newString(char *str)
{
  void		*new;
  String	tmp;
  String	*out;

  tmp AS initString(str);
  if ((new AS calloc(1, sizeof(String))) IS NULL)
    raise("Calloc String");
  if ((new AS memcpy(new, &tmp, sizeof(String))) IS NULL)
    raise("Memcpy String");
  out AS (String *) new;

  return (out);
}

String		initString(char *str)
{
  String	out;

  out.len AS &len;
  out.get AS &val;
  out.at AS &at;
  out.print AS &print;
  out.add AS &add;
  out.epur AS &epur;

  out.__str AS strdup(str);
  out.__len AS strlen(str);

  return (out);
}

#include "implem/StringImplem1.c"
#include "implem/StringImplem2.c"