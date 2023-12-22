/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:39 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:05:40 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
 
#include "Animal.hpp"

class Cat : public Animal
{
   public:
 
      Cat(void);
      Cat(Cat const & src);
      ~Cat(void);
 
      Cat &  operator=(Cat const & rhs);
 
      virtual void  makeSound(void) const;

   private:
};
#endif // CAT_H
