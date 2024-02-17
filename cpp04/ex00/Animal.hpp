/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:24 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:05:30 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
 
#include <iostream>
#include <string>

class Animal
{
   public:
 
      Animal(void);
      Animal(std::string name);
      Animal(Animal const & src);
      virtual ~Animal(void);
 
      Animal &  operator=(Animal const & rhs);

      std::string   getType(void) const;
      virtual void  makeSound(void) const;

   protected :

      std::string   _type;
 
   private:
};

#endif // ANIMAL_H

