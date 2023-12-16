/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:21 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:21 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H
 
#include <string>

class AMateria
{
    public:
 
       AMateria(void);
       AMateria(std::string const & type);
       AMateria(AMateria const & src);
       ~AMateria(void);
 
       AMateria &  operator=(AMateria const & rhs);
 
       std::string const & getType() const;

       virtual AMateria* clone() const = 0;
       virtual void use(ICharacter& target);

   protected:
       
       std::string type;
 
   private:
 
};
#endif // AMATERIA_H

