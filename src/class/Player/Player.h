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

#include "inventory.h"
#include "String.h"
#include "Alfred.h"

//TODO NORME

enum	s_CMD_NB
{
  KO = 0,
  FORWARD,
  EJECT,
  //TODO

}	t_CMD_NB;

typedef struct	s_egg
{
  int		time;
  Vec2I		position;
  String	*team;
}		t_egg;

typedef struct	s_todo
{
  int		time;
  String	*cmd;
  t_mineral	mineral;
  String	*msg;
}		t_todo;

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

CLASS			s_Player
{
  int			fd;
  Vec2I			position;
  Direction		direction;
  int			level;
  Inventory		inv;
  String		*name;
  String		*team;
  t_todo		todo[10];
};

Player			*newPlayer();
Player			initPlayer();

#endif //ZAPPY_PLAYER_H
