/*
** t_player.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_player.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Wed Jun 07 17:11:37 2017 Dimitri Wyzlic
** Last update Wed Jun 07 17:11:37 2017 Dimitri Wyzlic
*/

#include "Player.h"

static void	delete(THIS);

t_player			*new_player()
{
  t_player		*out;

  MALLOC(out, sizeof(t_player));
  *out = init_player();
  return (out);
}

t_player			init_player()
{
  t_player		out;

  out.position.x = 0;
  out.position.y = 0;
  out.direction = NORTH;
  out.level = 1;
  out.todo_time = 0;
  memset(out.todo, 0, sizeof(t_todo) * 10);
  init_inv(&(out.inv));
  out.delete = &delete;
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