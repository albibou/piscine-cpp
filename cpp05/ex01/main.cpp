#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){

  std::cout << "Parametric constructor test : " << std::endl;

  try {

    Form formA01("A01", 55, 100);
    std::cout << formA01 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

  std::cout << "Form with sign grade too high test : " << std::endl;

  try {

    Form formA02("A02", 0, 100);
    std::cout << formA02 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Form with exec grade too low test : " << std::endl;

  try {

    Form formA03("A03", 55, 99999);
    std::cout << formA03 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Sign a Form which grade is too high compared to bureaucrat (error in subject) : " << std::endl;

  try {

    Form formA04("A04", 1, 1);
    Bureaucrat bureaucrat1("Victor Newman", 150);

    bureaucrat1.signForm(formA04);
    std::cout << formA04 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Sign a Form succesful : " << std::endl;

  try {

    Form formA05("A05", 75, 75);
    Bureaucrat bureaucrat2("Catherine Chancelor", 1);

    bureaucrat2.signForm(formA05);
    std::cout << formA05 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Sign a Form with just the good grade : " << std::endl;

  try {

    Form formA06("A06", 75, 75);
    Bureaucrat bureaucrat3("Jack Abott", 75);

    bureaucrat3.signForm(formA06);
    std::cout << formA06 << std::endl;
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }

  return (0);
}
