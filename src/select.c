/*
** user.c for
**
** Made by Raphael Chriqui
** Login   <raphael.chriqui@epitech.net>
**
** Started on  Fri May 12 15:59:28 2017 Raphael Chriqui
** Last update Mon Jun 26 02:55:39 2017 Doom
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "arg_parser.h"
#include "Socket.h"
#include "Server.h"
#include "cmd.h"

static char	sig_int = 0;

static void	sigHandler(int n)
{
  (void)n;
  printf("\b\bt_server Closing\n");
  sig_int = 1;
}

static void			select_check(t_socket *socket, t_server *server, fd_set *rfds)
{
  int				index;

  index = -1;
  while (++index < FD_SETSIZE)
    {
      if (FD_ISSET(index, rfds))
	{
	  if (index == socket->fd)
	    {
	      socket->socket_accept(socket);
	      dprintf(socket->fd_client, MSG_WELCOME);
	      server->player_connect(server, socket->fd_client);
	    }
	  else
	    {
	      socket->fd_client = index;
	      if (index == server->gui->fd)
		check_cmd_gui(server, socket);
	      else
		check_cmd_client(server, socket);
	    }
	}
    }
}

static void			select_op(t_socket *socket, t_server *server)
{
  fd_set			rfds;
  struct timeval		tv;
  int				retval;
  PAIR_CP			*it;

  tv.tv_usec = 0;
  tv.tv_sec = 0;
  while (!sig_int)
    {
      tv.tv_usec = 0;
      tv.tv_sec = 0;
      FD_ZERO(&rfds);
      server->players->start_loop(server->players);
      while ((it = server->players->loop(server->players)))
	FD_SET(it->data->fd, &rfds);
      if (server->gui->fd != -1)
	FD_SET(server->gui->fd, &rfds);
      FD_SET(socket->fd, &rfds);
      tv.tv_sec = 2;
      if ((retval = select(server->players->len(server->players) + socket->fd + 2,
			   &rfds, NULL, NULL, &tv)) == -1 && !sig_int)
	RAISE("Select failed");
      else if (retval >= 0)
	  select_check(socket, server, &rfds);
      if (server->check_time(server) == false)
	continue;
      loop_todo(server);
      server->loop(server);
    }
}

int	        start(t_arg *args)
{
  t_server	*server;
  t_socket	*socket;

  signal(SIGINT, &sigHandler);
  (socket = get_socketi())->bind_listen(socket, args->port, args->maxt_players * 1);//TODO ADD maxTeam
  server = new_server(new_world_map(args->height, args->width), args); //TODO nbTeams
  select_op(socket, server);
  close(socket->fd);
  server->delete(server);
  free(socket);
  free(args->teamName);
  free(args);
  return (0);
}
