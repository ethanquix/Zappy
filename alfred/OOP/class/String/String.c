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
static String	*random_string(THIS, size_t len);
static void	delete(THIS);



String		*newString(char *str)
{
  String	*out;

  MALLOC(out, sizeof(String));
  *out = initString(str);

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
  out.random_string = &random_string;
  out.delete = &delete;

  if (str == NULL)
    {
      out.__str = strdup("");
      out.__len = 0;
    }
  else
    {
      out.__str = strdup(str);
      out.__len = (int) strlen(str);
    }
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