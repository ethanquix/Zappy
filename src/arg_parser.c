/*
** arg_parser.c for Zappy in /home/wyzlic_a/delivery/Zappy/arg_parser.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 23 16:01:09 2017 Dimitri Wyzlic
** Last update Fri Jun 23 16:01:09 2017 Dimitri Wyzlic
*/

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

Vector		*parse_team(char *name)
{
  printf("%s\n", name);
  return (NULL);
}

t_arg		*parse_arg(int nb, char **arg)
{
  t_arg		*out;

  out = init_arg_parser();
  int		c;
  const char	*short_opt = "p:fxyn:c";

  while((c = getopt(nb, arg, short_opt)) != -1)
    {
      optind
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
	out->teamName = parse_team(optarg);
    };
}