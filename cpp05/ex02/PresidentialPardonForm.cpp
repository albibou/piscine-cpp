#include "PresidentialPardonForm.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm(void) : AForm::AForm("Presidential Pardon Form", 25, 5), _target("home"){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("Presidential Pardon Form", 25, 5), _target(target){

  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : AForm::AForm(rhs), _target(rhs._target){

  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){

  if (this != &rhs) 
    this->_target = rhs.getTarget();
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs){

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

std::string   PresidentialPardonForm::getTarget(void) const{

  return this->_target;
} 

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void          PresidentialPardonForm::execute(Bureaucrat const & executor) const{

  try {

    checkFormExecRequirements(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
  }
  catch (const AForm::FormIsNotSignedException& e){
    throw AForm::FormIsNotSignedException();
  }
  catch (const AForm::GradeTooHighException& e){
    throw AForm::GradeTooHighException();
  }
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
/////////////////a//////////////////////////////////////////////////
