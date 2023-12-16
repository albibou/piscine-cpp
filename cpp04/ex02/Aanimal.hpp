/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:09:38 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:09:39 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H
 
#include <iostream>
#include <string>

class Aanimal
{
   public:
 
      Aanimal(void);
      Aanimal(std::string name);
      Aanimal(Aanimal const & src);
      virtual ~Aanimal(void);
 
      Aanimal &  operator=(Aanimal const & rhs);

      std::string   getType(void) const;
      virtual void  makeSound(void) const = 0;

   protected :

      std::string   type;
 
   private:
};

#endif // AANIMAL_H

