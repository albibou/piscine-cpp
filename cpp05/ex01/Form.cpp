/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:54:49 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:54:51 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

Form::Form(void) : _name("A00"), _isSigned(false), _gradeToSign(HIGHEST_GRADE), _gradeToExec(HIGHEST_GRADE){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

Form::Form(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){

  if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
    throw Form::GradeTooHighException();
  else if (gradeToExec > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
    throw Form::GradeTooLowException();
  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

Form::Form(Form const & rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec){

  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

Form::~Form(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

Form & Form::operator=(Form const & rhs){

  if (this != &rhs) 
    this->_isSigned = rhs.getIsSigned();
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs){

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

std::string const Form::getName(void) const{

  return this->_name;
}

bool              Form::getIsSigned(void) const{

  return this->_isSigned;
}

unsigned int      Form::getGradeToSign(void) const{

  return this->_gradeToSign;
}

unsigned int      Form::getGradeToExec(void) const{

  return this->_gradeToExec;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void          Form::beSigned(Bureaucrat const & bureaucrat){

  if (bureaucrat.getGrade() > _gradeToSign)
    throw Form::GradeTooLowException();
  else 
    _isSigned = true;
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  Form::GradeTooHighException::what() const throw() {

  return "The Form grade is too high !";
}

const char *  Form::GradeTooLowException::what() const throw() {

  return "The Form grade is too low !";
}
