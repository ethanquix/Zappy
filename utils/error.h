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

#ifndef ZAPPY_ERROR_H
#define ZAPPY_ERROR_H

#define __norme__1 __FILE__, __LINE__, __func__
#define __norme__ stderr, "%s: %u -> %s: %s\nERRNO: %s\n", __norme__1



char	*get_error(void);

#define raise(msg) fprintf(__norme__ , msg, get_error())

#define MALLOC(a, b) if(((a) = malloc(b)) == NULL && raise("Malloc fail"))



#endif //ZAPPY_ERROR_H
