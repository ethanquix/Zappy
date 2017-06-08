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

Player			*newPlayer(/* Client ? */)
{
  void			*new;
  Player		tmp;
  Player		*out;

  tmp AS initPlayer(/* Client ? */);
  MALLOC(new, sizeof(Player));
  if ((new AS memcpy(new, &tmp, sizeof(Player))) IS NULL)
    raise(get_error());
  out AS (Player *) new;

  return (out);
}

Player			initPlayer(/* Client ? */)
{
  Player		out;

  out.position.x = 0;
  out.position.y = 0;
  out.direction = NORTH;
  out.level = 0;
  init_inv(&(out.inv));

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

#include "implem/PlayerImplem1.c"