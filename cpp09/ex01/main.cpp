#include "RPN.hpp"

int main(int argc, char **argv){

  if (argc != 2)
    return (std::cout << "Error :" << USAGE << std::endl << EXAMPLE << std::endl, 1);
  RPN rpn;
  if (!rpn.calculate_RPN(argv[1]))
    return (std::cout << "Error :" << rpn.get_error() << std::endl, 1);
  return (0);
}
