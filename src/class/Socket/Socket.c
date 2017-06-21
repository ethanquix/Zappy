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
    socketi->socket_new(socketi);
  return (socketi);
}

static void	socket_new(THIS)
{
  MALLOC(this, sizeof(t_socket));
  this->in.sin_addr.s_addr = INADDR_ANY;
  this->in.sin_family = AF_INET;
  this->fd_client = 0;
  this->in_size = sizeof(this->in_client);
}

static void	bind_listen(THIS, int port, int nclient)
{
  this->in.sin_port = htons(port);
  this->fd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
  if (this->fd == -1)
    perror("socketi creation error");
  if (bind(this->fd, (const struct sockaddr*)(&this->in),
	   sizeof(this->in)) == -1)
    raise("Bind failed");
  if (listen(this->fd, port) == -1)
    raise("Listen failed");
}

static void	socket_acepte(THIS)
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
