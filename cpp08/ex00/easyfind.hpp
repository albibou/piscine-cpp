/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:04:07 by atardif           #+#    #+#             */
/*   Updated: 2024/05/08 17:04:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <string>
# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <vector>
# include <list>

template <typename T>
int easyfind(T const & container, int target){

  typename T::const_iterator it = std::find(container.begin(), container.end(), target);

  if (it == container.end())
    throw std::out_of_range("Target hasn't been found in given container");
  return std::distance(container.begin(), it);
}

#endif
