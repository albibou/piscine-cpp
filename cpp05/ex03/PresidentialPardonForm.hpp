/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:58:45 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:58:46 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

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


  private :

    std::string   _target;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rhs);

#endif
