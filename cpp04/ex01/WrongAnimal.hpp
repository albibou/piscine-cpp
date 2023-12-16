/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:09:03 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:09:04 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include "Animal.hpp"

class WrongAnimal
{
   public:
 
      WrongAnimal(void);
      WrongAnimal(std::string name);
      WrongAnimal(WrongAnimal const & src);
      virtual ~WrongAnimal(void);
 
      WrongAnimal &  operator=(WrongAnimal const & rhs);
 
      virtual void  makeSound(void) const;
      std::string   getType(void) const;
      
   protected :

      std::string   type;

   private:
};
#endif // WRONGANIMAL_H

