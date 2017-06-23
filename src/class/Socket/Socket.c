/*
** Socket.cpp for cpp_plazza
**
** Made by chriqu_r
** Login    <raphael.chriqui@epitech.net>
**
** Started on Fri Apr 28 09:34:00 2017 Raphael Chriqui
** Last update Mon Jun 12 21:10:24 2017 Raphael Chriqui
*/

#include "Alfred.h"
#include "Socket.h"
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

t_socket		*get_socketi()
{
  static t_socket	*socketi = NULL;

  if (!socketi)
    socketi = socket_new();
  return (socketi);
}


static void	bind_listen(THIS, int port, int maxclients)
{
  this->in.sin_port = 42;//htons(port);
  this->fd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
  if (this->fd == -1)
    raise("socketi creation error");
  if (bind(this->fd, (const struct sockaddr*)(&this->in),
	   sizeof(this->in)) == -1)
    raise("Bind failed");
  if (listen(this->fd, port) == -1)
    raise("Listen failed");
}

static void	socket_accept(THIS)
{
  this->fd_client = accept(this->fd,
			   (struct sockaddr *)&(this->in_client),
			   &this->in_size);
  if (this->fd_client == -1)
    {
      perror("Accept failed");
      close(this->fd);
      exit(1);
    }
}

static char	*socket_receive(THIS)
{
  char		*buff;
  ssize_t	index;

  MALLOC(buff, 1024 * sizeof(char));
  if ((index = read(this->fd_client, buff, 1024)) <= 0)
    {
      if (index < 0)
	perror("failed to read");
      close(this->fd_client);
      return (NULL);
    }
  else
    buff[index] = '\0';
  return (buff);
}

t_socket	*socket_new()
{
  t_socket	*socket;

  MALLOC(socket, sizeof(t_socket));
  socket->in.sin_addr.s_addr = INADDR_ANY;
  socket->in.sin_family = AF_INET;
  socket->fd_client = 0;
  socket->in_size = sizeof(socket->in_client);
  socket->socket_receive = &socket_receive;
  socket->bind_listen = &bind_listen;
  socket->socket_accept = &socket_accept;
  return (socket);
}
