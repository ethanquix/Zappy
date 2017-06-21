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

typedef class s_Player Player;

typedef enum e_dir Direction;

typedef	enum	e_dir
{
  NORTH = 0,
  SOUTH = 1,
  WEST = 2,
  EAST = 3
}		t_dir;

#undef THIS
#define THIS Player *this

class			s_Player
{
  int			fd;
  Vec2I			position;
  Direction		direction;
  int			level;
  Inventory		inv;
  String		*number;
  String		*team;
  //ClientInfo		*client info;
};

Player			*newPlayer(/* Client ? */);
Player			initPlayer(/* Client ? */);

#endif //ZAPPY_PLAYER_H
