/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:53:22 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:53:29 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat(void) : _name("Victor Newman"), _grade(LOWEST_GRADE){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name){

  if (grade < HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
  else 
    this->_grade = grade;
  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs._name), _grade(rhs._grade){

  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

Bureaucrat::~Bureaucrat(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){

  if (this != &rhs) 
    this->_grade = rhs.getGrade();
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs){

  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return o;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

std::string const Bureaucrat::getName(void) const{

  return this->_name;
}

unsigned int      Bureaucrat::getGrade(void) const{

  return this->_grade;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void          Bureaucrat::incrementGrade(void){

  if (this->_grade == HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else 
    this->_grade--;
  return ;
}

void          Bureaucrat::decrementGrade(void){

  if (this->_grade == LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
  else 
    this->_grade++;
  return ;
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  Bureaucrat::GradeTooHighException::what() const throw() {

  return "The grade is too high !";
}

const char *  Bureaucrat::GradeTooLowException::what() const throw() {

  return "The grade is too low !";
}
