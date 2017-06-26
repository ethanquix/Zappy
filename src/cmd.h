/*
** cmd.h for Zappy
**
** Made by chriqu_r
** Login    <raphael.chriqui@epitech.net>
**
** Started on Wed Jun 21 12:54:00 2017 Raphael Chriqui
** Last update Wed Jun 21 12:54:00 2017 Raphael Chriqui
*/

#ifndef ZAPPY_CMD_H
#define ZAPPY_CMD_H

#include "Server.h"
#include "config.h"

typedef void	(*gui_ptr)(Server *server, t_string *cmd);

typedef struct		s_gui
{
  const char		*name;
  const gui_ptr 	func;
}			t_gui;

typedef struct			s_cmd
{
  const char			*name;
  enum e_cmd_nb			action;
  int				time;
}				t_cmd;

void			loop_todo(Server *server);

void			check_cmd_client(Server *srv, t_socket *socket);
void			check_cmd_gui(Server *srv, t_socket *socket);

#endif //ZAPPY_CMD_H
