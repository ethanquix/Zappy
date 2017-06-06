/*
** String.h for Zappy in /home/wyzlic_a/delivery/Zappy/String.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 14:38:22 2017 Dimitri Wyzlic
** Last update Mon Jun 05 14:38:22 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_STRING_H
#define ZAPPY_STRING_H

#include <stdlib.h>
#include <memory.h>
#include "Alfred.h"

typedef class s_String String;

#define THIS String *this

class		s_String
{
  char		*__str;
  int		__len;

  int		(*len)(THIS);
  char		*(*get)(THIS);
  String	*(*print)(THIS);
  String	*(*add)(THIS, String *other);
  char 		(*at)(THIS, int emp);

  String	*(*epur)(THIS, char to_delete);
};

#undef THIS

String	*newString(char *str);

String	initString(char *str);

#endif //ZAPPY_STRING_H
