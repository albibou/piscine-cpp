#include "PmergeMe.hpp"

int main(int argc, char **argv){

  if (argc == 1)
    return (1);
  PmergeMe test;

  test.sort_vector(argv + 1);
  return (0);
}
