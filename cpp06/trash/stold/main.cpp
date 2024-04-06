#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

int main(int argc, char **argv){

  if (argc != 2)
    return 1;
  char  *remain;
  std::string litteral = argv[1];
  double num = strtold(litteral.c_str(), &remain);
  std::string rest(remain);
  std::cout << std::setprecision(999);
  if (!litteral.empty() && rest.empty() && )
    std::cout << "INT :" << num << std::endl;
  else
    std::cout << "Pas int" << std::endl;
  return 0;
}
