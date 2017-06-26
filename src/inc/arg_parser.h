/*
** arg_parser.h for Zappy in /home/wyzlic_a/delivery/Zappy/arg_parser.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 23 16:01:13 2017 Dimitri Wyzlic
** Last update Fri Jun 23 16:01:13 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_ARG_PARSER_H
#define ZAPPY_ARG_PARSER_H

#define DEFAULT_WIDTH 10
#define DEFAULT_HEIGHT 10
#define DEFAULT_PORT 4242
#define DEFAULT_MAX_CLIENT 10
#define DEFAULT_FREQ 100

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "Vector.h"
#include "Alfred.h"

typedef struct	s_arg
{
  int		port;
  int		width;
  int		height;
  t_vector	*teamName;
  int		maxt_players;
  int		freq;
}		t_arg;

t_arg		*parse_arg(int nb, char **arg);

#endif //ZAPPY_ARG_PARSER_H
