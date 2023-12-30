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

class Character : public ICharacter
{
    public:
 
       Character(void);
       Character(std::string name);
       Character(Character const & src);
       ~Character(void);
 
       Character &  operator=(Character const & rhs);
 
       virtual std::string const & getName() const;
       virtual void equip(AMateria* m);
       virtual void unequip(int idx);
       virtual void use(int idx, ICharacter& target);
       AMateria*    getMateria(int i) const;

   protected:
 
   private:

       std::string _name;
       AMateria    *_materiae[4];
};
#endif // CHARACTER_H

