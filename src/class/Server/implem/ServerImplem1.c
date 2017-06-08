/*
** ServerImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/ServerImplem1.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Fri Jun 09 01:16:13 2017 Dimitri Wyzlic
** Last update Fri Jun 09 01:16:13 2017 Dimitri Wyzlic
*/

#include "Server.h"

static Server		*forward(THIS, Player *player, int width, int height)
{
  if (player->direction == NORTH)
    {
      if (player->position.y - 1 >= 0)
	(player->position.y = player->position.y - 1); //&& client add command OK
//      else
	//bad player->client->add_command->(COMMAND_KO);
    }
  if (player->direction == SOUTH)
    {
      if (player->position.y + 1 < height)
	(player->position.y = player->position.y + 1); //&& client add command OK
//      else
      //bad player->client->add_command->(COMMAND_KO);
    }
  if (player->direction == EAST)
    {
      if (player->position.x + 1 < width)
	(player->position.x = player->position.x + 1); //&& client add command OK
//      else
      //bad player->client->add_command->(COMMAND_KO);
    }
  if (player->direction == WEST)
    {
      if (player->position.x - 1 >= 0)
	(player->position.x = player->position.x - 1); //&& client add command OK
//      else
      //bad player->client->add_command->(COMMAND_KO);
    }
}

static Server		*rotate(THIS, Player *player, Direction *direction)
{
  if (*direction == EAST)
    {
      if (player->direction == NORTH)
	return (player->direction = EAST, this);
      if (player->direction == EAST)
	return (player->direction = SOUTH, this);
      if (player->direction == SOUTH)
	return (player->direction = WEST, this);
      if (player->direction == WEST)
	return (player->direction = NORTH, this);
    }
  else
    {
      if (player->direction == NORTH)
	return (player->direction = WEST, this);
      if (player->direction == WEST)
	return (player->direction = SOUTH, this);
      if (player->direction == SOUTH)
	return (player->direction = EAST, this);
      if (player->direction == EAST)
	return (player->direction = NORTH, this);
    }
}