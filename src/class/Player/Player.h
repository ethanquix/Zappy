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

//#include "Server.h"
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
  Vec2I			position;
  Direction		direction;
  int			level;
  Inventory		inv;
  String		*number;
  //Client		*client;
//Team			*team;
//String		*name ???

  void			(*forward)(THIS);
  void			(*rotate)(THIS, Direction *direction);
  void			(*see)(THIS);
  void			(*get_inventory)(THIS);
  void			(*broadcast)(THIS, String *);
  void			(*unused_slot)(THIS);
  void			(*forkPlayer)(THIS);
  void			(*eject)(THIS);
  void			(*death)(THIS);
  void			(*take_obj)(THIS);
  void			(*place_obj)(THIS);
  void			(*incant)(THIS);
};

Player			*newPlayer(/* Client ? */);
Player			initPlayer(/* Client ? */);

#endif //ZAPPY_PLAYER_H
