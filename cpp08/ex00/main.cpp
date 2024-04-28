#include "easyfind.hpp"

void  list_tests(void){

  std::cout << std::endl << "Let's run tests on list type container" << std::endl;
  std::list<int>  int_list;

  for (int i = 0; i < 10; i++)
    int_list.push_back(i);

  std::cout << std::endl << "We'll try our function with values that are in the container" << std::endl;
  try {
    int test = easyfind(int_list, 3);
    std::cout << test << std::endl;
    test = easyfind(int_list, 1);
    std::cout << test << std::endl;
    test = easyfind(int_list, 7);
    std::cout << test << std::endl;
    test = easyfind(int_list, 9);
    std::cout << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "We'll now try with value that is not in the container" << std::endl;
  try {
    int test = easyfind(int_list, -1000);
    std::cout << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return ;
}

void  vector_tests(void){

  std::cout << "Let's run tests on vector type container" << std::endl;
  std::vector<int>  int_vector;

  for (int i = 0; i < 10; i++)
    int_vector.push_back(i);

  std::cout << std::endl << "We'll try our function with values that are in the container" << std::endl;
  try {
    int test = easyfind(int_vector, 3);
    std::cout << test << std::endl;
    test = easyfind(int_vector, 1);
    std::cout << test << std::endl;
    test = easyfind(int_vector, 7);
    std::cout << test << std::endl;
    test = easyfind(int_vector, 9);
    std::cout << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "We'll now try with value that is not in the container" << std::endl;
  try {
    int test = easyfind(int_vector, -1000);
    std::cout << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return ;
}

int main(void){

  vector_tests();
  list_tests();
  return 0;
}
