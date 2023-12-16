/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:56:28 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:56:30 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
 
ClapTrap::ClapTrap(void) : name("default"), hitPoints(10), energyPoints(10), attackDamage(0){
     
    std::cout << "Default ClapTrap Constructor called" << std::endl;
    return ;
}
 
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
     
    std::cout << "Parametric ClapTrap Constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const & src){

    *this = src;
    std::cout << "Copy ClapTrap Constructor called" << std::endl;
    return ;
}
 
ClapTrap::~ClapTrap(void){
 
    std::cout << "Default ClapTrap Destructor called" << std::endl;
    return ;
}
 
ClapTrap & ClapTrap::operator=(ClapTrap const & rhs){

    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
    return *this;
}

void    ClapTrap::attack(const std::string& target){

    if (!this->hitPoints)
        std::cout << "ClapTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->energyPoints)
        std::cout << "ClapTrap " << this->name << " has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount){

    if (amount > this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " has no hit points left and fall incounscious" << std::endl;
        return ;
    }
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " is attacked, causing " << amount << " points of damage! He has " << this->hitPoints << " left" << std::endl;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount){
    
    if (!this->hitPoints)
        std::cout << "ClapTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->energyPoints)
        std::cout << "ClapTrap " << this->name << " has no energy points left and can't do anything" << std::endl;
    else 
    {
        std::cout << "ClapTrap " << this->name << " repairs itself and get " << amount << " hit points back, for a total of " << this->hitPoints + amount << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    }
    return ;
}
