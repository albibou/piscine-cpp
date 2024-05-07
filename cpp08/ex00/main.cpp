#include "easyfind.hpp"

void  list_tests(void){

  std::cout << std::endl << "Let's run tests on list type container" << std::endl;
  std::list<int>  int_list;

  int_list.push_back(42);
  int_list.push_back(-1);
  int_list.push_back(7);

  std::cout << "Let's display the list and it's indexes" << std::endl;
  size_t i = 0;
  for (std::list<int>::const_iterator it = int_list.begin(); it != int_list.end(); it++, i++)
    std::cout << "int_list[" << i << "] = " << *it << std::endl;

  std::cout << std::endl << "We'll try our function with values that are in the container" << std::endl;
  try {
    int test = easyfind(int_list, -1);
    std::cout << "-1 found at index : " << test << std::endl;
    test = easyfind(int_list, 7);
    std::cout << "7 found at index : " << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Let's add some values and retry" << std::endl;

  int_list.push_front(100);
  int_list.push_front(101);
  int_list.push_front(102);

  std::cout << std::endl << "Let's display the list and it's indexes" << std::endl;
  i = 0;
  for (std::list<int>::const_iterator it = int_list.begin(); it != int_list.end(); it++, i++)
    std::cout << "int_list[" << i << "] = " << *it << std::endl;

  std::cout << std::endl;
  try {
    int test = easyfind(int_list, -1);
    std::cout << "-1 found at index : " << test << std::endl;
    test = easyfind(int_list, 7);
    std::cout << "7 found at index : " << test << std::endl;
    test = easyfind(int_list, 100);
    std::cout << "100 found at index : " << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "We'll now try with value that is not in the container" << std::endl;
  try {
    int test = easyfind(int_list, -1000);
    std::cout << "found at index : " << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return ;
}

void  vector_tests(void){

  std::cout << std::endl << "Let's run tests on vector type container" << std::endl;
  std::vector<int>  int_vector;

  int_vector.push_back(42);
  int_vector.push_back(-1);
  int_vector.push_back(7);

  std::cout << "Let's display the vector and it's indexes" << std::endl;
  size_t i = 0;
  for (std::vector<int>::const_iterator it = int_vector.begin(); it != int_vector.end(); it++, i++)
    std::cout << "int_vector[" << i << "] = " << *it << std::endl;

  std::cout << std::endl << "We'll try our function with values that are in the container" << std::endl;
  try {
    int test = easyfind(int_vector, -1);
    std::cout << "-1 found at index : " << test << std::endl;
    test = easyfind(int_vector, 7);
    std::cout << "7 found at index : " << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Let's add some values and retry" << std::endl;

  int_vector.push_back(100);
  int_vector.push_back(101);
  int_vector.push_back(102);

  std::cout << std::endl << "Let's display the vector and it's indexes" << std::endl;
  i = 0;
  for (std::vector<int>::const_iterator it = int_vector.begin(); it != int_vector.end(); it++, i++)
    std::cout << "int_vector[" << i << "] = " << *it << std::endl;

  std::cout << std::endl;
  try {
    int test = easyfind(int_vector, -1);
    std::cout << "-1 found at index : " << test << std::endl;
    test = easyfind(int_vector, 7);
    std::cout << "7 found at index : " << test << std::endl;
    test = easyfind(int_vector, 102);
    std::cout << "102 found at index : " << test << std::endl;
  }
  catch(const std::exception & e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "We'll now try with value that is not in the container" << std::endl;
  try {
    int test = easyfind(int_vector, -1000);
    std::cout << "found at index : " << test << std::endl;
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
