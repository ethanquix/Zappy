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
static void	delete(THIS);



String		*newString(char *str)
{
  void		*new;
  String	tmp;
  String	*out;

  tmp = initString(str);
  if ((new = calloc(1, sizeof(String))) IS NULL)
    raise("Calloc String");
  if ((new = memcpy(new, &tmp, sizeof(String))) IS NULL)
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
  out.delete = &delete;

  out.__str = strdup(str);
  out.__len = strlen(str);

  return (out);
}

static void	delete(THIS)
{
  if (this->__str)
    free(this->__str);
  free(this);
}

#include "implem/StringImplem1.c"
#include "implem/StringImplem2.c"