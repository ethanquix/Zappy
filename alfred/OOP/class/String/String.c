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
static t_string	*print(THIS);
static int	len(THIS);
static char	at(THIS, int at);
static t_string	*add(THIS, t_string *other);
static t_string	*epur(THIS, char to_delete);
static t_string	*random_string(THIS, size_t len);
static void	delete(THIS);

t_string		*new_string(char *str)
{
  t_string		*out;

  MALLOC(out, sizeof(t_string));
  *out = init_string(str);
  return (out);
}

t_string	init_string(char *str)
{
  t_string	out;

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
      out.__len = (int)strlen(str);
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