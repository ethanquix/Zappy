///*
//** PlayerImplem1.c for Zappy in /home/wyzlic_a/delivery/Zappy/PlayerImplem1.c
//**
//** Made by Dimitri Wyzlic
//** Login   <dimitri1.wyzlic@epitech.eu>
//**
//** Started on  Thu Jun 08 19:27:16 2017 Dimitri Wyzlic
//** Last update Thu Jun 08 19:27:16 2017 Dimitri Wyzlic
//*/
//
//#include "Player.h"
//
//static void			forward(THIS, int width, int height)
//{
//  if (this->direction == NORTH)
//    {
//      if (this->position.y - 1 >= 0)
//	(this->position.y = this->position.y - 1); //&& client add command OK
////      else
//	//bad this->client->add_command->(COMMAND_KO);
//    }
//  if (this->direction == SOUTH)
//    {
//      if (this->position.y + 1 < height)
//	(this->position.y = this->position.y + 1); //&& client add command OK
////      else
//      //bad this->client->add_command->(COMMAND_KO);
//    }
//  if (this->direction == EAST)
//    {
//      if (this->position.x + 1 < width)
//	(this->position.x = this->position.x + 1); //&& client add command OK
////      else
//      //bad this->client->add_command->(COMMAND_KO);
//    }
//  if (this->direction == WEST)
//    {
//      if (this->position.x - 1 >= 0)
//	(this->position.x = this->position.x - 1); //&& client add command OK
////      else
//      //bad this->client->add_command->(COMMAND_KO);
//    }
//}
//
//static void		rotate(THIS, Direction *direction)
//{
//  if (*direction == EAST)
//    {
//      if (this->direction == NORTH)
//	return (void) (this->direction = EAST);
//      if (this->direction == EAST)
//	return (void) (this->direction = SOUTH);
//      if (this->direction == SOUTH)
//	return (void) (this->direction = WEST);
//      if (this->direction == WEST)
//	return (void) (this->direction = NORTH);
//    }
//  else
//    {
//      if (this->direction == NORTH)
//	return (void) (this->direction = WEST);
//      if (this->direction == WEST)
//	return (void) (this->direction = SOUTH);
//      if (this->direction == SOUTH)
//	return (void) (this->direction = EAST);
//      if (this->direction == EAST)
//	return (void) (this->direction = NORTH);
//    }
//}