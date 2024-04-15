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
