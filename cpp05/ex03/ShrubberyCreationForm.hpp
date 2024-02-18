#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm{

  public :

    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
    virtual ~ShrubberyCreationForm(void);

    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

    std::string   getTarget(void) const;
    void          execute(Bureaucrat const & executor) const;

    class FileOpeningException : public std::exception{

      public :
        const char * what() const throw();
    }; 

  private :

    std::string   _target;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif
