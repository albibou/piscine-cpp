#include "PmergeMe.hpp"

int main(int argc, char **argv){

  if (argc == 1)
    return (1);
  PmergeMe test;

  try {

    test.sort_vector(argv + 1);
  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
