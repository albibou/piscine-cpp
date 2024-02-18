#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# ifndef PRINT
#  define PRINT 0
# endif

class Form;

class Intern{

  public :

    Intern(void);
    Intern(Intern const & rhs);
    ~Intern(void);

    Intern & operator=(Intern const & rhs);

    AForm *  makeForm(std::string name, std::string target);  

  private :

};

std::ostream & operator<<(std::ostream & o, Intern const & rhs);

#endif
