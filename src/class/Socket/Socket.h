/*
** my_irc.h for myirc.h in /home/teck/home/PSU/PSU_2016_myirc/include
**
** Made by Lheen Teck
** Login   <olivier.gillon@epitech.eu>
**
** Started on  Wed May 24 16:01:04 2017 Lheen Teck
** Last update Mon Jun 12 21:16:38 2017 Raphael Chriqui
*/

#ifndef MYIRC_H
# define MYIRC_H

#include <sys/socket.h>
#include <netinet/in.h>


typedef struct s_socket t_socket;

#undef THIS
#define THIS t_socket *this

t_socket		*get_socketi();
t_socket		*socket_new();

struct	s_socket
{
  int				fd;
  int				fd_client;
  struct sockaddr_in		in;
  struct sockaddr_in		in_client;
  socklen_t			in_size;
  void				(*bind_listen)(THIS, int port, int nclient);
  void				(*socket_accept)(THIS);
  char				*(*socket_receive)(THIS);
};

#endif
