/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:31 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:32 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H
 
#include "AMateria.hpp"

class Character
{
    public:
 
       Character(void);
       Character(Character const & src);
       ~Character(void);
 
       Character &  operator=(Character const & rhs);
 
   protected:
 
   private:
 
       AMateria    *_materiae[4];
};
#endif // CHARACTER_H

