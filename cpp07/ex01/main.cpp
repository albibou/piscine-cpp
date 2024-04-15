#include "iter.hpp"

int main(void){

  std::cout << "Test on an int array" << std::endl;
  int int_array[] = {0, 1, 2, 3};
  iter(int_array, sizeof(int_array) / sizeof(*int_array), test<int>);
  
  std::cout << std::endl << "Test on an float array" << std::endl;
  float float_array[] = {0.0f, 1.5f, 2.3f, 3.1f};
  iter(float_array, sizeof(float_array) / sizeof(*float_array), test<float>);
 
  std::cout << std::endl << "Test on a char array" << std::endl;
  char char_array[] = {'E', 'n', ' ', 'b', 'o', 'm', 'b', 'e'};
  iter(char_array, sizeof(char_array) / sizeof(*char_array), test<char>);
 
  return 0;
}
