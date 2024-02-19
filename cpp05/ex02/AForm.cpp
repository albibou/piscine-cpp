/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:55:24 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:55:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

AForm::AForm(void) : _name("A00"), _isSigned(false), _gradeToSign(HIGHEST_GRADE), _gradeToExec(HIGHEST_GRADE){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

AForm::AForm(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){

  if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
    throw AForm::GradeTooHighException();
  else if (gradeToExec > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
    throw AForm::GradeTooLowException();
  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

AForm::AForm(AForm const & rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec){

  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

AForm::~AForm(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

AForm & AForm::operator=(AForm const & rhs){

  if (this != &rhs) 
    this->_isSigned = rhs.getIsSigned();
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs){

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

std::string const AForm::getName(void) const{

  return this->_name;
}

bool              AForm::getIsSigned(void) const{

  return this->_isSigned;
}

unsigned int      AForm::getGradeToSign(void) const{

  return this->_gradeToSign;
}

unsigned int      AForm::getGradeToExec(void) const{

  return this->_gradeToExec;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void          AForm::beSigned(Bureaucrat const & bureaucrat){

  if (bureaucrat.getGrade() > _gradeToSign)
    throw AForm::GradeTooLowException();
  else 
    _isSigned = true;
}

void          AForm::checkFormExecRequirements(Bureaucrat const & executor) const{

  if (!this->_isSigned)
    throw FormIsNotSignedException();
  if (executor.getGrade() > this->_gradeToExec)
    throw GradeTooHighException();
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  AForm::GradeTooHighException::what() const throw() {

  return "The Form grade is too high !";
}

const char *  AForm::GradeTooLowException::what() const throw() {

  return "The Form grade is too low !";
}

const char *  AForm::FormIsNotSignedException::what() const throw() {

  return "This form isn't signed yet !";
}
