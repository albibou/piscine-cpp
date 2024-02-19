#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// Good Names for forms 
// Robotomy Request Form
// Presidential Pardon Form
// Shrubbery Creation Form

int main(void){

   try{

     Intern intern1;

     Bureaucrat bureaucrat1("Victor Newman", 1);

     AForm *form1 = intern1.makeForm("Robotomy Request Form", "Gerard Jugnot");
     AForm *form2 = intern1.makeForm("Presidential Pardon Form", "Patrick Dils");
     AForm *form3 = intern1.makeForm("Shrubbery Creation Form", "Babylon");
     AForm *form4 = intern1.makeForm("Random Name", "Casimir");

     bureaucrat1.signForm(*form1);
     bureaucrat1.signForm(*form2);
     bureaucrat1.signForm(*form3);

     bureaucrat1.executeForm(*form1);
     bureaucrat1.executeForm(*form2);
     bureaucrat1.executeForm(*form3);
  }
  catch (std::exception const & e){

    std::cerr << e.what() << std::endl;
  }
  return (0);
}
