/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:55:34 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:55:35 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{

  public :

    AForm(void);
    AForm(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec);
    AForm(AForm const & rhs);
    virtual ~AForm(void);

    AForm & operator=(AForm const & rhs);

    std::string const       getName(void) const;
    bool                    getIsSigned(void) const;
    unsigned int            getGradeToSign(void) const;
    unsigned int            getGradeToExec(void) const;

    void              beSigned(Bureaucrat const & bureaucrat);
    void              checkFormExecRequirements(Bureaucrat const & executor) const;

    virtual void      execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception{

      public :
        const char * what() const throw(); 
    }; 

    class GradeTooLowException : public std::exception{

      public :
        const char * what() const throw();
    }; 

    class FormIsNotSignedException : public std::exception{

      public :
        const char * what() const throw();
    }; 

  private :

    std::string const   _name;
    bool                _isSigned;
    unsigned int const  _gradeToSign;
    unsigned int const  _gradeToExec;


};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif
