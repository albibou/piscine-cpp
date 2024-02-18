#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm{

  public :

    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const & rhs);
    virtual ~PresidentialPardonForm(void);

    PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

    std::string   getTarget(void) const;
    void          execute(Bureaucrat const & executor) const;

    //class FileOpeningException : public std::exception{

      public :
        const char * what() const throw();
    }; 

  private :

    std::string   _target;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs);

#endif
