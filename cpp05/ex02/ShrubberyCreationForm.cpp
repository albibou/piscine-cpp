#include "ShrubberyCreationForm.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm(void) : _name("A00"), _isSigned(false), _gradeToSign(HIGHEST_GRADE), _gradeToExec(HIGHEST_GRADE){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){

  if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
    throw ShrubberyCreationForm::GradeTooHighException();
  else if (gradeToExec > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
    throw ShrubberyCreationForm::GradeTooLowException();
  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec){

  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){

  if (this != &rhs) 
    this->_isSigned = rhs.getIsSigned();
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs){

  o << "Form : " << rhs.getName();
  if (rhs.getIsSigned())
    o << " is actually signed." << std::endl;
  else 
    o << " isn't actually signed." << std::endl;
  o << "Grade " << rhs.getGradeToSign() << " is required to sign it" << std::endl;
  o << "Grade " << rhs.getGradeToExec() << " is required to execute it" << std::endl;
  return o;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

std::string const ShrubberyCreationForm::getName(void) const{

  return this->_name;
}

bool              ShrubberyCreationForm::getIsSigned(void) const{

  return this->_isSigned;
}

unsigned int      ShrubberyCreationForm::getGradeToSign(void) const{

  return this->_gradeToSign;
}

unsigned int      ShrubberyCreationForm::getGradeToExec(void) const{

  return this->_gradeToExec;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void          ShrubberyCreationForm::beSigned(Bureaucrat const & bureaucrat){

  if (bureaucrat.getGrade() > _gradeToSign)
    throw ShrubberyCreationForm::GradeTooLowException();
  else 
    _isSigned = true;
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  ShrubberyCreationForm::GradeTooHighException::what() const throw() {

  return "The Form grade is too high !";
}

const char *  ShrubberyCreationForm::GradeTooLowException::what() const throw() {

  return "The Form grade is too low !";
}
