/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:25:01 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 19:13:47 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){

    return;
}

HumanB::~HumanB(void){
    //if (this->_weapon)
        //delete this->_weapon;
    return;
}

void    HumanB::attack(void)
{
    if (!(this->_weapon))
        std::cout << this->_name << " does not hold weapon" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon weapon)
{
    Weapon  *dest = new Weapon(weapon.getType());
    if (!dest)
    {
        std::cout << "Allocation failed" << std::endl;
        return ;
    }
    this->_weapon = dest;
    return ;
}
