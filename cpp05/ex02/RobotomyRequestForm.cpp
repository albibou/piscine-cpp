#include "RobotomyRequestForm.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm(void) : AForm::AForm("Robotomy Request Form", 72, 45), _target("home"){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("Robotomy Request Form", 72, 45), _target(target){

  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) : AForm::AForm(rhs), _target(rhs._target){

  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){

  if (this != &rhs) 
    this->_target = rhs.getTarget();
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs){

  o << "Form : " << rhs.getName();
  if (rhs.getIsSigned())
    o << " is actually signed." << std::endl;
  else 
    o << " isn't actually signed." << std::endl;
  o << "Grade " << rhs.getGradeToSign() << " is required to sign it" << std::endl;
  o << "Grade " << rhs.getGradeToExec() << " is required to execute it" << std::endl;
  o << "It's target is " << rhs.getTarget() << " ." << std::endl;

  return o;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

std::string   RobotomyRequestForm::getTarget(void) const{

  return this->_target;
} 

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void          RobotomyRequestForm::execute(Bureaucrat const & executor) const{

  try {

    checkFormExecRequirements(executor);

    std::cout << "Drilling Noises :" << std::endl;
    std::cout << "Brrrr Btttt Brt Btr BRrrrrrrR !!! " << std::endl;
    if (rand() & 1)
      std::cout << _target << " has been succesfully robotomized!" << std::endl;
    else 
      std::cout << _target << "'s robotomy failed..." << std::endl;
    
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  } 
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////
