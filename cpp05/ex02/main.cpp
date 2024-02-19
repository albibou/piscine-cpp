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
    ShrubberyCreationForm  form3("SaintOuen");
    ShrubberyCreationForm  form4("");

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl << std::endl;

    std::cout << "1 / Let's try Presidential Pardon Form :" << std::endl;

    std::cout << std::endl << "Test with unsigned form : "  << std::endl;
    bureaucrat4.executeForm(form1);

    std::cout << std::endl << "Test with signed form but bureaucrat not high-graded : "  << std::endl;
    bureaucrat4.signForm(form1);
    bureaucrat1.signForm(form1);
    bureaucrat4.executeForm(form1);

    std::cout << std::endl << "Test with signed form and high-graded bureaucrat "  << std::endl;
    bureaucrat1.executeForm(form1);

    std::cout << std::endl << std::endl << "2 / Let's try Robotomy Request Form :" << std::endl;

    std::cout << std::endl << "Test with unsigned form : "  << std::endl;
    bureaucrat4.executeForm(form2);

    std::cout << std::endl << "Test with signed form but bureaucrat not high-graded : "  << std::endl;
    bureaucrat4.signForm(form2);
    bureaucrat1.signForm(form2);
    bureaucrat4.executeForm(form2);

    std::cout << std::endl << "Test with signed form and high-graded bureaucrat "  << std::endl;
    bureaucrat1.executeForm(form2);
    std::cout << std::endl << "Test with signed form and high-graded bureaucrat "  << std::endl;
    bureaucrat1.executeForm(form2);

    std::cout << std::endl << std::endl << "3 / Let's try Shrubbery Creation Form :" << std::endl;

    std::cout << std::endl << "Test with unsigned form : "  << std::endl;
    bureaucrat4.executeForm(form3);

    std::cout << std::endl << "Test with signed form but bureaucrat not high-graded : "  << std::endl;
    bureaucrat4.signForm(form3);
    bureaucrat1.signForm(form3);
    bureaucrat4.executeForm(form3);

    std::cout << std::endl << "Test with signed form and high-graded bureaucrat "  << std::endl;
    bureaucrat1.executeForm(form3);
  }
  catch (std::exception const & e){

    std::cerr << e.what() << std::endl;
  }
  return (0);
}
