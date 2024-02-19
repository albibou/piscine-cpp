/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:58:20 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:58:21 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// Good Names for forms 
// Robotomy Request Form
// Presidential Pardon Form
// Shrubbery Creation Form

int main(void){

   try{

     Intern intern1;

     Bureaucrat bureaucrat1("Victor Newman", 1);

     std::cout << "Make an intern create a Robotomy Request Form test :" << std::endl << std::endl;

     AForm *form1 = intern1.makeForm("Robotomy Request Form", "Gerard Jugnot");
     if (form1)
     {
       std::cout << *form1 << std::endl;
       bureaucrat1.signForm(*form1);
       bureaucrat1.executeForm(*form1);
       delete(form1);
     }
     else 
       std::cout << "Form couldn't be created, tests won't be conducted" << std::endl;

     std::cout << std::endl << "Make an intern create a Presidential Pardon Form test :" << std::endl << std::endl;

     AForm *form2 = intern1.makeForm("Presidential Pardon Form", "Patrick Dils");
     if (form2)
     {
       std::cout << *form2 << std::endl;
       bureaucrat1.signForm(*form2);
       bureaucrat1.executeForm(*form2);
       delete(form2);
     }
     else 
       std::cout << "Form couldn't be created, tests won't be conducted" << std::endl;

     std::cout << std::endl << "Make an intern create a Shrubbery Creation Form test :" << std::endl << std::endl;

     AForm *form3 = intern1.makeForm("Shrubbery Creation Form", "Babylon");
     if (form3)
     {
       std::cout << *form3 << std::endl;
       bureaucrat1.signForm(*form3);
       bureaucrat1.executeForm(*form3);
       delete(form3);
     }
     else 
       std::cout << "Form couldn't be created, tests won't be conducted" << std::endl;

     std::cout << std::endl << "Make an intern create a Unexisting form test :" << std::endl << std::endl;

     AForm *form4 = intern1.makeForm("Random Name", "Casimir");
     if (form4)
     {
       std::cout << *form4 << std::endl;
       bureaucrat1.signForm(*form4);
       bureaucrat1.executeForm(*form4);
       delete(form4);
     }
     else 
       std::cout << "Form couldn't be created, tests won't be conducted" << std::endl;
  }
  catch (std::exception const & e){

    std::cerr << e.what() << std::endl;
  }
  return (0);
}
