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
#include <pthread.h>
#include "my_irc.h"

static char	sig_int = 0;

static void	sigHandler(int n)
{
  (void)n;
  printf("\b\bServer Closing\n");
  sig_int = 1;
}

static void			select_check(t_irc *irc, fd_set *rfds)
{
  int				index;

  index = -1;
  while (++index < FD_SETSIZE)
    {
      if (FD_ISSET(index, rfds))
	{
	  if (index == irc->socket.fd)
	    {
	      accept_socket(&irc->socket);
	      create_data_s(irc);
	    }
	  else
	    get_client_line(irc, index);
	}
    }
}

static void			select_op(t_irc *irc)
{
  fd_set			rfds;
  struct timeval		tv;
  int				retval;
  int				index;

  tv.tv_usec = 0;
  while (!sig_int)
    {
      FD_ZERO(&rfds);
      index = irc->nclients;
      while (--index >= 0)
	FD_SET(irc->clients[index].fd, &rfds);
      tv.tv_sec = 2;
      if ((retval = select(irc->socket.fd + irc->nclients,
			   &rfds, NULL, NULL, &tv)) == -1)
	{
	  perror("select failed");
	  exit(1);
	}
      else if (retval == 0)
	continue ;
      else
	select_check(irc, &rfds);
    }
}

int	        main(int ac, char *av[])
{
  t_irc		irc;

  if (ac != 2)
    {
      printf("Usage : ./server port\n");
      return (1);
    }
  signal(SIGINT, &sigHandler);
  socket_new(SERVER, atoi(av[1]), &irc.socket);
  irc.nclients = 0;
  irc.clients = NULL;
  irc.channels = NULL;
  irc.nchannels = 0;
  irc.socket.fd_client = irc.socket.fd;
  create_data_s(&irc);
  select_op(&irc);
  close(irc.socket.fd);
  return (0);
}
