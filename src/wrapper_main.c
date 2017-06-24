/*
** wrapper_main.c for Zappy in /home/wyzlic_a/delivery/Zappy/wrapper_main.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Sat Jun 24 19:40:59 2017 Dimitri Wyzlic
** Last update Sat Jun 24 19:40:59 2017 Dimitri Wyzlic
*/

#include "cmd.h"

static Vector			*wrapper_ko(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_forward(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_right(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_left(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_see(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_get_inv(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_broadcast(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_unused(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_fork(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_eject(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_take(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_place(Server *server, Player *player, t_mineral mineral, String *msg);
static Vector			*wrapper_incant(Server *server, Player *player, t_mineral mineral, String *msg);

static Vector	*(*wrapper_function[13])(Server *server, Player *player, t_mineral mineral, String *msg) =
	{
		wrapper_ko,
		wrapper_forward,
		wrapper_right,
		wrapper_left,
		wrapper_see,
		wrapper_get_inv,
		wrapper_broadcast,
		wrapper_unused,
		wrapper_fork,
		wrapper_eject,
		wrapper_take,
		wrapper_place,
		wrapper_incant,
	};

void		respond(Vector *vector)
{
  void		*ret;
  t_response	*resp;

  vector->start_loop(vector);

  while ((ret = vector->loop(vector)) != NULL)
    {
      resp = (t_response *)ret;
      dprintf(resp->fd, "%s\n", resp->msg->__str);
    }
}

void		loop_todo(Server *server)
{
  int		i;
  PairCP	*it;

  server->players->start_loop(server->players);
  while ((it = server->players->loop(server->players)) != NULL)
    {
      i = 0;
      while (i < MAX_CMD)
	{
	  if (it->data->todo[i].time == 0)
	    respond(wrapper_function[it->data->todo->action](server, it->data, it->data->todo[i].mineral, it->data->todo[i].msg));
	  //TODO IF TIME < 0 ALORS DUCOUP ON PEUT OVERRIDE DESSUS
	  it->data->todo->time -= 1; //TODO CALC MEILLEUR TEMPS QUE 1
	  i += 1;
	}
    }
}

#include "wrapper_1.c"
#include "wrapper_2.c"
#include "wrapper_3.c"