#ifndef EASYFIND_H
# define EASYFIND_H

# include <string>
# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <vector>
# include <list>

template <typename T>
const int & easyfind(T const & container, int target){

  typename T::const_iterator it = std::find(container.begin(), container.end(), target);

  if (it == container.end())
    throw std::out_of_range("Target hasn't been found in given container");
  return *it;
}

#endif
