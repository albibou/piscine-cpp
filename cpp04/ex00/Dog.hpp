/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:50 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:05:53 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
 
#include "Animal.hpp"

class Dog : public Animal
{
   public:
 
      Dog(void);
      Dog(Dog const & src);
      ~Dog(void);
 
      Dog &  operator=(Dog const & rhs);
 
      void  makeSound(void) const;

   private:
};
#endif // DOG_H

