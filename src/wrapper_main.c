/*
** wrapper_main.c for Zappy in /home/wyzlic_a/delivery/Zappy/wrapper_main.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Sat Jun 24 19:40:59 2017 Dimitri Wyzlic
** Last update Sun Jun 25 15:21:35 2017 Doom
*/

#include "cmd.h"

static t_vector			*wrapper_ko(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_forward(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_right(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_left(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_see(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_get_inv(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_broadcast(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_unused(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_fork(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_eject(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_take(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_place(Server *server, t_player *player, t_mineral mineral, t_string *msg);
static t_vector			*wrapper_incant(Server *server, t_player *player, t_mineral mineral, t_string *msg);

static t_vector	*(*wrapper_function[13])(Server *server, t_player *player, t_mineral mineral, t_string *msg) =
{
  &wrapper_ko,
  &wrapper_forward,
  &wrapper_right,
  &wrapper_left,
  &wrapper_see,
  &wrapper_get_inv,
  &wrapper_broadcast,
  &wrapper_unused,
  &wrapper_fork,
  &wrapper_eject,
  &wrapper_take,
  &wrapper_place,
  &wrapper_incant,
};

void		respond(t_vector *vector)
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
  PAIR_CP	*it;

  server->players->start_loop(server->players);
  while ((it = server->players->loop(server->players)) != NULL)
    {
      i = 0;
      while (i < MAX_CMD)
	{
	  if (it->data->todo[i].action != C_NOTHING && it->data->todo[i].time == 0)
	    {
 	      respond(wrapper_function[it->data->todo[i].action - 1](server, it->data, it->data->todo[i].mineral, it->data->todo[i].msg));
	      it->data->todo[i].action = C_NOTHING;
	      //TODO IF TIME < 0 ALORS DUCOUP ON PEUT OVERRIDE DESSUS
	      // 	  it->data->todo_time -= it->data->todo[i].time; TODO
	    }
	  if ((it->data->todo_time -= 1) <= 0)
	    it->data->todo_time = 0;
	  it->data->todo[i].time -= 1; //TODO CALC MEILLEUR TEMPS QUE 1
	  i += 1;
	}
    }
}

#include "wrapper_1.c"
#include "wrapper_2.c"
#include "wrapper_3.c"
