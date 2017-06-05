/*
** error.c for Zappy in /home/wyzlic_a/delivery/Zappy/error.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 15:16:37 2017 Dimitri Wyzlic
** Last update Mon Jun 05 15:16:37 2017 Dimitri Wyzlic
*/

#include "error.h"

char	*get_error(void)
{
    int	errnum = errno;
    return (strerror(errnum));
}