/*
** t_player.h for Zappy in /home/wyzlic_a/delivery/Zappy/t_player.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 17:11:37 2017 Dimitri Wyzlic
** Last update Mon Jun 26 14:19:40 2017 Doom
*/

#ifndef ZAPPY_PLAYER_H
#define ZAPPY_PLAYER_H

#include "config.h"
#include "inventory.h"
#include "String.h"
#include "Alfred.h"

enum	e_cmd_nb
{
  C_NOTHING = 0,
  C_KO,
  C_FORWARD,
  C_RIGHT,
  C_LEFT,
  C_LOOK,
  C_INVENTORY,
  C_BROADCAST,
  C_UNUSED,
  C_FORK,
  C_EJECT,
  C_TAKE,
  C_SET,
  C_INCANT
};


static char*	direction_name[] =
  {
    "NORTH",
    "EAST",
    "SOUTH",
    "WEST"
  };

typedef	enum	e_dir
{
  NORTH = 0,
  EAST = 1,
  SOUTH = 2,
  WEST = 3
}		t_dir;

#undef THIS

typedef struct	s_todo
{
  enum e_cmd_nb	action;
  int		time;
  t_mineral	mineral;
  t_string	*msg;
}		t_todo;

typedef CLASS		s_player
{
  int			fd;
  t_vec_ii			position;
  t_dir			direction;
  int			level;
  t_inv			inv;
  t_string		*name;
  t_string		*team;
  struct s_todo		todo[MAX_CMD];
  int			todo_time;
  void			(*delete)(struct s_player *this);
  int			cur_food_loss;
}			t_player;

t_player			*new_player();
t_player			init_player();

#define THIS t_player *this

#endif //ZAPPY_PLAYER_H
