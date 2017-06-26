/*
** t_serverImplem5.c for Zappy in /home/wyzlic_a/delivery/Zappy/t_serverImplem5.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 26 03:24:21 2017 Dimitri Wyzlic
** Last update Mon Jun 26 03:24:21 2017 Dimitri Wyzlic
*/

#include "Server.h"

static bool	check_levelup(THIS, t_player *player);

static t_response	*fork_player(THIS, t_player *player)
{
  t_response		*resp;
  int			it;
  t_egg			*egg;

  MALLOC(egg, ST(egg));
  egg->pos = player->position;
  egg->is_hatched = false;
  egg->time = TIME_SERVER_FORK / this->freq;
  it = this->team_index->get(this->team_index, player->team->__str);
  this->teams[it]->eggs->add(this->teams[it]->eggs, egg);
  MALLOC(resp, sizeof(t_response));
  resp->fd = player->fd;
  resp->name = player->name;
  resp->msg = new_string(MSG_OK);
  return (resp);
}

static t_server		*apply_fork(THIS)
{
  int			i;
  void			*it;
  t_egg			*egg;

  i = 0;
  while (i < this->nb_teams)
    {
      this->teams[i]->eggs->start_loop(this->teams[i]->eggs);
      while ((it = this->teams[i]->eggs->loop(this->teams[i]->eggs)))
	{
	  egg = (t_egg *)it;
	  if (egg->is_hatched == false && egg->time <= 0)
	    egg->is_hatched = true;
	  if (egg->is_hatched == false)
	    egg->time -= 1;
	}
      i += 1;
    }
  return (this);
}

static t_response	*incant(THIS, t_player *player)
{
  t_serv_todo		*todo;
  t_response		*resp;

  MALLOC(todo, ST(todo));
  MALLOC(resp, ST(resp));
  resp->fd = player->fd;
  resp->msg = new_string(MSG_OK);
  resp->name = player->name;
  todo->player_fd = player->fd;
  todo->time = TIME_SERVER_INCANT / this->freq;
  todo->action = CMD_SERVER_INCANT;

  if (check_levelup(this, player) == false)
    {
      resp->msg = new_string(MSG_KO);
      return (resp);
    }
  this->todo->add(this->todo, todo);
  return (resp);
}

static t_server		*apply_incant(THIS, t_serv_todo *todo)
{
  PAIR_CP		*it;
  t_player		*current;

  current = this->players->get(this->players, todo->player_fd);
  if (check_levelup(this, current) == false)
    {
      return (this);
    }
  this->players->start_loop(this->players);
  while ((it = this->players->loop(this->players)) != NULL)
    {
      if (it->data->position.x == current->position.x && it->data->position.y == current->position.y)
	it->data->level += 1;
    }
  current->level += 1;
  return (this);
}

#include "implem/ServerImplem6.c"