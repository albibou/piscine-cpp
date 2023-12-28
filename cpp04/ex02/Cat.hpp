/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:08:31 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:08:32 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
 
#include "Aanimal.hpp"
#include "Brain.hpp"

#define STD_CATIDEA "Human you suckers"

class Cat : public Aanimal
{
   public:
 
      Cat(void);
      Cat(Cat const & src);
      ~Cat(void);
 
      Cat &  operator=(Cat const & rhs);
 
      virtual void  makeSound(void) const;
      void  fillIdea(std::string idea, int index);
      void  displayIdeas(void) const;
      void  displayanIdea(int index) const;

   private:

      Brain *_brain;
};
#endif // CAT_H
