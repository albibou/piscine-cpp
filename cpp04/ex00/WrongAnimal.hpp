/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:06:35 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:06:38 by atardif          ###   ########.fr       */
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
      ~WrongAnimal(void);
 
      WrongAnimal &  operator=(WrongAnimal const & rhs);
 
      void  makeSound(void) const;
      std::string   getType(void) const;
      
   protected :

      std::string   type;

   private:
};
#endif // WRONGANIMAL_H

