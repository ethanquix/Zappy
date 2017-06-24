/*
** Player.h for Zappy in /home/wyzlic_a/delivery/Zappy/Player.h
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 17:11:37 2017 Dimitri Wyzlic
** Last update Wed Jun 07 17:11:37 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_PLAYER_H
#define ZAPPY_PLAYER_H

#include "config.h"
#include "inventory.h"
#include "String.h"
#include "Alfred.h"

//TODO NORME

#define TIME_FORWARD 7
#define TIME_RIGHT 7
#define TIME_LEFT 7
#define TIME_LOOK 7
#define TIME_INVENTORY 1
#define TIME_BROADCAST 7
#define TIME_UNUSED 0
#define TIME_FORK 42
#define TIME_EJECT 7
#define TIME_TAKE 7
#define TIME_SET 7
#define TIME_INCANT 300

enum	e_cmd_nb
{
  C_KO = 0,
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

typedef CLASS s_Player Player;

typedef enum e_dir Direction;

typedef	enum	e_dir
{
  NORTH = 0,
  EAST = 1,
  SOUTH = 2,
  WEST = 3
}		t_dir;

#undef THIS
#define THIS Player *this

typedef struct	s_todo
{
  enum e_cmd_nb	action;
  int		time;
  t_mineral	mineral;
  String	*msg;
}		t_todo;

CLASS			s_Player
{
  int			fd;
  Vec2I			position;
  Direction		direction;
  int			level;
  Inventory		inv;
  String		*name;
  String		*team;
  struct s_todo		todo[MAX_CMD];

  void			(*delete)(THIS);
};

Player			*newPlayer();
Player			initPlayer();


#endif //ZAPPY_PLAYER_H
