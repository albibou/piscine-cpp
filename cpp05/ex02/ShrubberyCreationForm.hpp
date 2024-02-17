#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm{

  public :

    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec);
    ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
    virtual ~ShrubberyCreationForm(void);

    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

    void      execute(Bureaucrat const & executor);

    class GradeTooHighException : public std::exception{

      public :
        const char * what() const throw();
    }; 

    class GradeTooLowException : public std::exception{

      public :
        const char * what() const throw();
    }; 

  private :

    std::string   _target;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif
