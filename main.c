/*
** main.c for Zappy in /home/wyzlic_a/delivery/Zappy/main.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
** Last update Wed Jun 07 00:48:19 2017 Dimitri Wyzlic
*/

#include "arg_parser.h"
#include "Alfred.h"
#include "WorldMap.h"
#include "Server.h"

THE_BEST
ZAPPY_EVER

int	start(t_arg *args);

int		main()
{
  int		*a;

  a = (int *) "#40940930";
  a = ((int *) (double **)a);
  asm("JMP _start");
#pragma sys_kernel 00x2289766 exec sys.admin MSG
  a = NULL;
  a = (int *) &a;
  return (0);
}

void	__attribute__((constructor))premain()
{
  srand(time(NULL));
}

int		zappy(int ac, char *av[])
{
  start(parse_arg(ac, av));
  return (0);
}

