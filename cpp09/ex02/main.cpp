#include "PmergeMe.hpp"

int main(int argc, char **argv){

  if (argc < 2){
    std::cout << "Error: Use with at list two positive integers as arguments." << std::endl;
    return (1);
  }
  try {
    PmergeMe<std::vector> vec_to_sort;
    PmergeMe<std::deque> deque_to_sort;
    vec_to_sort.sort_container(argv + 1, PRINT_CONTAINER);
    deque_to_sort.sort_container(argv + 1, NO_PRINT_CONTAINER);
    vec_to_sort.print_time_to_sort("vector");
    deque_to_sort.print_time_to_sort("deque");

  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
