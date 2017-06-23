/*
** error.h for Zappy in /home/wyzlic_a/delivery/Zappy/error.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 15:16:50 2017 Dimitri Wyzlic
** Last update Mon Jun 05 15:16:50 2017 Dimitri Wyzlic
*/

#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include <stdlib.h>

#ifndef ZAPPY_ERROR_H
#define ZAPPY_ERROR_H

#define __norme__1 __FILE__, __LINE__, __PRETTY_FUNCTION__
#define __norme__ stderr, "%s: %u -> %s: %s\nERRNO: %s\n"

char	*get_error(void);
void	*__raise__(char *msg, char *file, unsigned int l, char *f);

#define raise(msg) (__raise__(msg, __norme__1))

#define MALLOC(a, b) (((a) = malloc(b)) == NULL && raise("Malloc fail"))



#endif //ZAPPY_ERROR_H
