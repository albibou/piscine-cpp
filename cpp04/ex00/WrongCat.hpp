/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:06:48 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:06:50 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H
 
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
   public:
 
      WrongCat(void);
      WrongCat(WrongCat const & src);
      ~WrongCat(void);
 
      WrongCat &  operator=(WrongCat const & rhs);
 
      void  makeSound(void) const;
   private:
};
#endif // WRONGCAT_H

