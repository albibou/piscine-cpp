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
