#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm{

  public :

    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExec);
    RobotomyRequestForm(RobotomyRequestForm const & rhs);
    virtual ~RobotomyRequestForm(void);

    RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

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

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif
