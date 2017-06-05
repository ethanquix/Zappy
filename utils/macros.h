/*
** macros.hpp for Zappy in /home/wyzlic_a/delivery/Zappy/macros.hpp
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 13:36:14 2017 Dimitri Wyzlic
** Last update Mon Jun 05 13:36:14 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_MACROS_HPP
#define ZAPPY_MACROS_HPP

//Troll

#define ZAPPY 42
#define THE_BEST int main[ZAPPY] asm("NotMain");
#define ZAPPY_EVER int zappy() asm("main");


//Python Like
#define OR ||
#define AND &&

//Utils
#define RESET(a,b)   memset(a,b,sizeof(a))

//List manipulation
#define ARRAY_LENGTH(A) (sizeof(A) / sizeof(A[0]))

#endif //ZAPPY_MACROS_HPP
