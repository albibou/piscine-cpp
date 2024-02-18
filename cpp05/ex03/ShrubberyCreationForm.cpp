#include "ShrubberyCreationForm.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm::AForm("Shrubbery Creation Form", 145, 137), _target("home"){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("Shrubbery Creation Form", 145, 137), _target(target){

  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec), _target(rhs._target){

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
  {
    this->_target = rhs.getTarget();
    this->_isSigned = rhs.getIsSigned();
  }
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
  o << "It's target is " << rhs.getTarget() << " ." << std::endl;

  return o;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

std::string   ShrubberyCreationForm::getTarget(void) const{

  return this->_target;
} 

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void          ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

  try {

    checkFormExecRequirements(executor);
    std::ofstream newfile;

    newfile.open(_target.c_str(), std::fstream:out);
    if (!newfile.is_open())
      throw FileOpeningException();
    newfile <<                ,@@@@@@@,
       ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
   `&%\ ` /%&'    |.|        \ '|8'
       |o|        | |         | |
       |.|        | |         | |
    \\/ ._\\/_/__/  ,\_\/__\\/.  \_\/__/_;
   return (void)(newfile.close()) 
  }
  catch (const std::exception& e){

    std::cerr << e.what() << std::endl;
  } 
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  ShrubberyCreationForm::FileOpeningException::what() const throw() {

  return "Error opening File !";
}

