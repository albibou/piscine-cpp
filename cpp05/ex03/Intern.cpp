#include "Intern.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

Intern::Intern(void){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

Intern::Intern(Intern const & rhs){

  (void)rhs;
  //insert assignation
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

Intern::~Intern(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

Intern & Intern::operator=(Intern const & rhs){

  if (this != &rhs) 
  {
    //insert assignation
  }
  (void)rhs;
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, Intern const & rhs){

  (void)rhs;
  /*o << insert output desired*/;
  return o;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////
 
AForm *   Intern::makeForm(std::string name, std::string target){

  std::string formNames[3] = {"Robotomy Request Form", "Presidential Pardon Form", "Shrubbery Creation Form"};

  for (int i = 0; i < 3 ; i++){

    if (formNames[i] == name)
      break ;
  }

  switch (i) {

    case 0 :
      AForm * Robot == new RobotomyRequestForm(target);
      return (std::cout << "Intern creates Robotomy Request Form." << std::endl, Robot);
    case 1 :
      AForm * Pardon == new PresidentialPardonForm(target);
      return (std::cout << "Intern creates Presidential Pardon Form ." << std::endl, Pardon);
    case 2 :
      AForm * Shrubbery == new ShrubberyCreationForm(target);
      return (std::cout << "Intern creates Shrubbery Creation Form." << std::endl, Shrubbery);
    default 
      return (std::cout << "Intern couldn't find a form with this name ..." << std::endl, NULL;)
  }
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

