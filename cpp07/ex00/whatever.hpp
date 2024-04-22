/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:45:17 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:45:18 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

# include <string>
# include <iostream>

template <typename T>

void  swap(T & lhs, T & rhs){

  T tmp = lhs;
  lhs = rhs;
  rhs = tmp;
  return ;
}

template <typename T>

T const & max(T const & lhs, T const & rhs){
  return (lhs>=rhs ? lhs : rhs);
}

template <typename T>

T const & min(T const & lhs, T const & rhs){
  return (lhs<=rhs ? lhs : rhs);
}

#endif
