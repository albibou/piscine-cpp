/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:08:46 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:08:47 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
 
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
   public:
 
      Dog(void);
      Dog(Dog const & src);
      ~Dog(void);
 
      Dog &  operator=(Dog const & rhs);
 
      void  makeSound(void) const;
      void  fillIdea(std::string idea, int index);
      void  displayIdeas(void) const;
      void  displayanIdea(int index) const;

   private:

      Brain *_brain;
};
#endif // DOG_H

