/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:14:01 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:14:02 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H
 
#include "AMateria.hpp"
#include <string>
#include <iostream>

class AMateria;

class ICharacter
{
    public:
 
       virtual ~ICharacter(void){};
       virtual std::string const & getName() const = 0;
       virtual void equip(AMateria* m) = 0;
       virtual void unequip(int idx) = 0;
       virtual void use(int idx, ICharacter& target) = 0;
};
#endif // ICHARACTER_H

