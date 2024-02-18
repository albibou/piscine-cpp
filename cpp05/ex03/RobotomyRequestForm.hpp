#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm{

  public :

    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const & rhs);
    virtual ~RobotomyRequestForm(void);

    RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

    std::string   getTarget(void) const;
    int           getRatio(void) const;
    void          execute(Bureaucrat const & executor) const;

  private :

    std::string   _target;
    int           _ratio;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif
