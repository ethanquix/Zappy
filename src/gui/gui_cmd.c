/*
** gui_cmd.c for Zappy
**
** Made by chriqu_r
** Login    <raphael.chriqui@epitech.net>
**
** Started on Sun Jun 25 18:21:00 2017 Raphael Chriqui
** Last update Sun Jun 25 18:21:00 2017 Raphael Chriqui
*/

#include "Server.h"
#include "cmd.h"

static void		get_map_size(t_server *server);
static void		get_tile_info(t_server *server);
static void		get_players_by_team(t_server *server);
static void		get_map_size(t_server *server, t_string *cmd);
static void		get_tile_info(t_server *server, t_string *cmd);
static void		get_players_by_team(t_server *server, t_string *cmd);
static void		get_team_list(t_server *server, t_string *cmd);
static void		get_player_info(t_server *server, t_string *cmd);
static void		set_ressource(t_server *server, t_string *cmd);

static const t_gui	client_cmd[] =
	{
		{ "get_map_size", &get_map_size },
		{ "get_tile_info", &get_tile_info},
		{ "get_players_by_team", &get_players_by_team},
		{ "get_team_list", &get_team_list },
		{ "get_player_info", &get_player_info },
		{ "set_ressource", &set_ressource },
		{ NULL, NULL }
	};

void			check_cmd_gui(t_server *server, t_socket *socket)
{
  char			*cmd;
  char			*to_check;
  int			index;

  if ((cmd = socket->socket_receive(socket)) == NULL)
    return (void)(server->gui->fd = -1);
  to_check = strtok(strdup(cmd), " \r\n");
  index = 0;
  while (client_cmd[index].name != NULL && to_check &&
	 strcasecmp(client_cmd[index].name, to_check) != 0)
    index++;
  if (client_cmd[index].name && to_check)
    client_cmd[index].func(server);
  else
    dprintf(server->gui->fd, "Invalid command\n");
}

static void	get_map_size(t_server *server)
{
  UNUSED(cmd);
  dprintf(server->gui->fd, "%d %d\n", server->map->width, server->map->height);
}

static void		get_tile_info(t_server *server)
{
  char			*tmp;
  int			x;
  int			y;

  tmp = strtok(NULL, " ");
  if (tmp == NULL)
    return (void)dprintf(server->gui->fd, "Not enough arguments\n");
  x = atoi(tmp);
  tmp = strtok(NULL, " ");
  if (tmp == NULL)
    return (void)dprintf(server->gui->fd, "Not enough arguments\n");
  y = atoi(tmp);
  if (x >= server->map->width || x < 0 || y >= server->map->height || y < 0)
    dprintf(server->gui->fd, "Invalid position\n");
  else
    dprintf(server->gui->fd, "%s\n", server->__get_tile_inv(server, x, y)->__str);
}

static void		get_players_by_team(t_server *server)
{
  char			*tmp;
  t_string		*out;
  PAIR_CP		*it;

  //TODO DOIT FAIL PARCEQUE NOM TEAM A ENCORE \n
  tmp = strtok(cmd->__str, " ");
  tmp = strtok(NULL, " ");
  if (tmp == NULL)
    return (void)dprintf(server->gui->fd, "Not enough arguments\n");
  out = new_string("");
  server->players->start_loop(server->players);
  while ((it = server->players->loop(server->players)))
    {
      printf("DEBUG : tmp[%s], it[%s]\n", tmp, it->data->team->__str);
      if (strcmp(it->data->team->__str, tmp) == 0)
	out->add(out, new_string(" "))->add(out, it->data->name);
    }
  if (out->len(out) <= 1)
    dprintf(server->gui->fd, "none\n");
  else
    dprintf(server->gui->fd, "%s\n", out->__str);
}

#include "gui_cmd_2.c"