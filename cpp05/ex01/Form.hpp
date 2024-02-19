/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:54:58 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:54:59 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{

  public :

    Form(void);
    Form(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec);
    Form(Form const & rhs);
    ~Form(void);

    Form & operator=(Form const & rhs);

    std::string const       getName(void) const;
    bool                    getIsSigned(void) const;
    unsigned int            getGradeToSign(void) const;
    unsigned int            getGradeToExec(void) const;

    void              beSigned(Bureaucrat const & bureaucrat);

    class GradeTooHighException : public std::exception{

      public :
        const char * what() const throw();
    }; 

    class GradeTooLowException : public std::exception{

      public :
        const char * what() const throw();
    }; 

  private :

    std::string const   _name;
    bool                _isSigned;
    unsigned int const  _gradeToSign;
    unsigned int const  _gradeToExec;


};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
