/*
** error.c.c for Zappy in /home/wyzlic_a/delivery/Zappy/error.c.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 23 15:35:05 2017 Dimitri Wyzlic
** Last update Fri Jun 23 15:35:05 2017 Dimitri Wyzlic
*/

#include "error.h"

char	*get_error(void)
{
  int	errnum = errno;
  return (strerror(errnum));
}

void	*__raise__(char *msg)
{
  fprintf(__norme__, msg, get_error());
  exit(1);
}