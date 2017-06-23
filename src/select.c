/*
** user.c for
**
** Made by Raphael Chriqui
** Login   <raphael.chriqui@epitech.net>
**
** Started on  Fri May 12 15:59:28 2017 Raphael Chriqui
** Last update Mon Jun 12 17:31:36 2017 Lheen Teck
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
  printf("\b\bServer Closing\n");
  sig_int = 1;
}

static void			select_check(t_socket *socket, Server *server, fd_set *rfds)
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
	      server->player_connect(server, socket->fd_client);
	    }
	  else
	    {
	      socket->fd_client = index;
	      check_cmd_client(socket->socket_receive(socket), server);
	    }
	}
    }
}

static void			select_op(t_socket *socket, Server *server)
{
  fd_set			rfds;
  struct timeval		tv;
  int				retval;
  PairCP			*it;

  tv.tv_usec = 0;
  while (!sig_int)
    {
      FD_ZERO(&rfds);
      server->players->start_loop(server->players);
      while ((it = server->players->loop(server->players)))
	FD_SET(it->data->fd, &rfds);
      tv.tv_sec = 2;
      if ((retval = select(server->players->len(server->players) + 1,
			   &rfds, NULL, NULL, &tv)) == -1 && !sig_int)
	raise("Select failed");
      else if (retval == 0)
	continue ;
      else
	select_check(socket, server, &rfds);
    }
}

int	        start(t_arg *args)
{
  Server	*server;
  t_socket	*socket;

  signal(SIGINT, &sigHandler);
  (socket = get_socketi())->bind_listen(socket, args->port, args->maxPlayers * 1);//TODO ADD maxTeam
  server = newServer(newWorldMap(args->height, args->width), args); //TODO nbTeams
  select_op(socket, server);
  close(socket->fd);
  return (0);
}
