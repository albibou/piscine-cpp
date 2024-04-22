/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:45:25 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:45:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>
# include <string>

template <typename T, typename U>

void  iter(T *addr, size_t len, U funct){

  for (size_t i = 0; i < len; i++)
    funct(addr[i]);
  return ;
}

template <typename T>

void  test(T arg){
  std::cout << arg << std::endl;
  return ;
}

#endif
