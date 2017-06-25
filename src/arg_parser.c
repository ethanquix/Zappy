/*
** arg_parser.c for Zappy in /home/wyzlic_a/delivery/Zappy/arg_parser.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 23 16:01:09 2017 Dimitri Wyzlic
** Last update Fri Jun 23 16:01:09 2017 Dimitri Wyzlic
*/

#include <String.h>
#include "arg_parser.h"

t_arg		*init_arg_parser()
{
  t_arg		*out;

  MALLOC(out, sizeof(t_arg));
  out->width = DEFAULT_WIDTH;
  out->height = DEFAULT_HEIGHT;
  out->port = DEFAULT_PORT;
  out->maxPlayers = DEFAULT_MAX_CLIENT;
  out->freq = DEFAULT_FREQ;
  out->teamName = newVector();
  return (out);
}

Vector		*parse_team(int idx, char **arg, int max)
{
  Vector	*tmp;

  tmp = newVector();
  idx = idx - 1;
  while (idx < max)
    {
      tmp->add(tmp, newString(arg[idx]));
      idx += 1;
    }
  return (tmp);
}

t_arg		*verif_arg(t_arg *src)
{
  if (src->port < 0)
    raise("Port must be positive");
  if (src->freq < 2 || src->port > 10000)
    raise("-f option only accepts integer values between 2 and 10000");
  if (src->width < 10 || src->width > 30)
    raise("-x option only accepts integer values between 10 and 30");
  if (src->height < 10 || src->height > 30)
    raise("-y option only accepts integer values between 10 and 30");
  if (src->maxPlayers < 1)
    raise("-c option only accepts integer values greater or equal to 1");
  if (src->teamName->len(src->teamName) <= 0)
    raise("You need to specify team name");
  //TODO CHECK IF NOT TEAM DOUBLON
  return (src);
}

t_arg		*parse_arg(int nb, char **arg)
{
  t_arg		*out;

  out = init_arg_parser();
  int		c;
  const char	*short_opt = "p:fxyn:c";

  while((c = getopt(nb, arg, short_opt)) != -1)
    {
      if (c == 'p')
	out->port = atoi(optarg);
      if (c == 'f')
	out->freq = atoi(optarg);
      if (c == 'x')
	out->width = atoi(optarg);
      if (c == 'h')
	out->height = atoi(optarg);
      if (c == 'c')
	out->maxPlayers = atoi(optarg);
      if (c == 'n')
	out->teamName = parse_team(optind, arg, nb);
    };
  return (verif_arg(out));
}