/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:55:41 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:55:42 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include "AForm.hpp"

# ifndef PRINT
#  define PRINT 0
# endif

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class AForm;

class Bureaucrat{

  public :

    Bureaucrat(void);
    Bureaucrat(std::string const name, unsigned int grade);
    Bureaucrat(Bureaucrat const & rhs);
    ~Bureaucrat(void);

    Bureaucrat & operator=(Bureaucrat const & rhs);

    std::string const getName(void) const;
    unsigned int      getGrade(void) const;

    void              incrementGrade(void);
    void              decrementGrade(void);
    void              signForm(AForm & form);
    void              executeForm(AForm const & form);

    class GradeTooHighException : public std::exception{

      public :
        const char * what() const throw();
    }; 

    class GradeTooLowException : public std::exception{

      public :
        const char * what() const throw();
    }; 

  private :

    std::string const _name;
    unsigned int      _grade;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
