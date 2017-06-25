/*
** Player.c for Zappy in /home/wyzlic_a/delivery/Zappy/Player.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 17:11:37 2017 Dimitri Wyzlic
** Last update Wed Jun 07 17:11:37 2017 Dimitri Wyzlic
*/

#include "Player.h"

static void	delete(THIS);

Player			*newPlayer(/* Client ? */)
{
  Player		*out;

  MALLOC(out, sizeof(Player));
  *out = initPlayer(/* Client ? */);

  return (out);
}

Player			initPlayer(/* Client ? */)
{
  Player		out;

  out.position.x = 0;
  out.position.y = 0;
  out.direction = NORTH;
  out.level = 1;
  out.todo_time = 0;
  memset(out.todo, 0, sizeof(t_todo) * 10);
  init_inv(&(out.inv));

  out.delete = &delete;
//  out.forward = &forward;
//  out.rotate = &rotate;
//  out.see= &see;
//  out.get_inventory = &get_inventory;
//  out.broadcast = &broadcast;
//  out.unused_slot = &unused_slot;
//  out.forkPlayer = &forkPlayer;
//  out.eject = &eject;
//  out.death = &death;
//  out.take_obj = &take_obj;
//  out.place_obj = &place_obj;
//  out.incant = &incant;
  return (out);
}

static void	delete(THIS)
{
  int		i;

  i = 0;
  this->name->delete(this->name);
  if (this->team)
    this->team->delete(this->team);
  while (i < MAX_CMD)
    {
      if (this->todo[i].msg != NULL)
	this->todo[i].msg->delete(this->todo[i].msg);
      i += 1;
    }
  free (this);
}

#include "implem/PlayerImplem1.c"