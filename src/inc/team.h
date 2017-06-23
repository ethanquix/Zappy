/*
** team.h for Zappy in /home/wyzlic_a/delivery/Zappy/team.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 16 15:34:33 2017 Dimitri Wyzlic
** Last update Fri Jun 16 15:34:33 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_TEAM_H
#define ZAPPY_TEAM_H

#include <String.h>

typedef struct		s_egg
{
  int			time;
  Vec2I			pos;
}			t_egg;

typedef struct		s_team
{
  int			current_nb_player;
  String		*name;
  Vector		*eggs;

}			t_team;

#endif //ZAPPY_TEAM_H
