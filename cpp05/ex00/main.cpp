#include "Bureaucrat.hpp"

int main(void){

  std::cout << "Default Constructor Test : " << std::endl;

  try {

    Bureaucrat  test1;
    std::cout << test1 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

std::cout << "Parametric Constructor Test : " << std::endl;

  try {

    Bureaucrat  test2("Jack Abott", 92);
    std::cout << test2 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

std::cout << "Grade too high Construction Test : " << std::endl;

  try {

    Bureaucrat  test3("Dany Romalotti", 0);
    std::cout << test3 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

std::cout << std::endl << "Grade too low Construction Test : " << std::endl;

  try {

    Bureaucrat  test4("Paul Williams", 90000);
    std::cout << test4 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

std::cout << std::endl << "Increment grade method test : " << std::endl;

  try {

    Bureaucrat  test5("Catherine Chancelor", 5);
    std::cout << test5 << std::endl;
    for (int i = 0; i < 10; i++)
    {
      test5.incrementGrade();
      std::cout << test5 << std::endl;
    }
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

std::cout << std::endl << "Decrement grade method test : " << std::endl;

  try {

    Bureaucrat  test6("Drucilla Winter", 145);
    std::cout << test6 << std::endl;
    for (int i = 0; i < 10; i++)
    {
      test6.decrementGrade();
      std::cout << test6 << std::endl;
    }
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

  return (0);
}
