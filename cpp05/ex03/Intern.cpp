/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:58:12 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:58:13 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

  (void)rhs;
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, Intern const & rhs){

  (void)rhs;
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

  int i;
  AForm * tmp;

  for (i = 0; i < 3 ; i++){

    if (formNames[i] == name)
      break ;
  }

  switch (i) {

    case 0 :
      tmp = new RobotomyRequestForm(target);
      std::cout << "Intern creates Robotomy Request Form." << std::endl;
      break ;
    case 1 :
      tmp = new PresidentialPardonForm(target);
      std::cout << "Intern creates Presidential Pardon Form ." << std::endl;
      break ;
    case 2 :
      tmp = new ShrubberyCreationForm(target);
      std::cout << "Intern creates Shrubbery Creation Form." << std::endl;
      break ;
    default :
      tmp = NULL;
      std::cout << "Intern couldn't find a form with this name ..." << std::endl;
  }
  return tmp;
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

