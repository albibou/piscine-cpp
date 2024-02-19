/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:59:31 by atardif           #+#    #+#             */
/*   Updated: 2024/02/19 19:59:32 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
