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

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec), _target(rhs._target){

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
  {
    this->_target = rhs.getTarget();
    this->_isSigned = rhs.getIsSigned();
  }
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

    checkFormExecRequirements();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox";
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  }
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////
