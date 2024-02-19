#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){

  std::cout << "Can't initialize Abstract class test (uncomment the main) :" << std::endl;

  //AForm test();
  //
  try{

    std::cout << "Creation of bureaucrats" << std::endl << std::endl;

    Bureaucrat  bureaucrat1("Victor Newman", 1);
    Bureaucrat  bureaucrat2("Catherine Chancelor", 30);
    Bureaucrat  bureaucrat3("Jack Abott", 100);
    Bureaucrat  bureaucrat4("Dany Romalotti", 150);

    std::cout << bureaucrat1;
    std::cout << bureaucrat2;
    std::cout << bureaucrat3;
    std::cout << bureaucrat4 << std::endl;

    std::cout << "Creation of Forms" << std::endl; 

    PresidentialPardonForm form1("Michael Blanc");
    RobotomyRequestForm    form2("Pablo Cheron");
    ShrubberyCreationForm  form3();

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
  }
  catch (std::exception const & e){

    std::cerr << e.what() << std::endl;
  }
  return (0);
}
