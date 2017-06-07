/*
** OO_macros.hpp for Zappy in /home/wyzlic_a/delivery/Zappy/OO_macros.hpp
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 13:36:41 2017 Dimitri Wyzlic
** Last update Mon Jun 05 13:36:41 2017 Dimitri Wyzlic
*/

#ifndef ZAPPY_OO_MACROS_HPP
#define ZAPPY_OO_MACROS_HPP

#define ALFRED_MF(RET, NAME, ...) RET (*NAME)(__VA__ARGS__)

#define class struct

#define VGET(var, vect, pos) var = ((typeof(var))(vect)->get(vect, pos))
#define VGETNP(var, vect, pos) var = ((typeof(var))(vect).get(&(vect), pos))


#endif //ZAPPY_OO_MACROS_HPP
