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
#define ZAPPY_ERROR

#define raise(msg) fprintf(stderr, "%s: %u -> %s: %s\n", __FILE__, __LINE__, __func__, msg);

char	*get_error(void);

#endif //ZAPPY_ERROR_H
