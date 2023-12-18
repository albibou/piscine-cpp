/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:56:40 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:56:41 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
 
ScavTrap::ScavTrap(void){
 
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Default ScavTrap Constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Parametric ScavTrap Constructor called" << std::endl;
    return ;
}
 
ScavTrap::ScavTrap(ScavTrap const & src){
 
    *this = src; 
    std::cout << "Copy ScavTrap Constructor called" << std::endl;
    return ;
}
 
ScavTrap::~ScavTrap(void){
 
    std::cout << "Default ScavTrap Destructor called" << std::endl;
    return ;
}
 
ScavTrap & ScavTrap::operator=(ScavTrap const & rhs){
    
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
    return *this;
}

void    ScavTrap::attack(const std::string& target){

    if (!this->hitPoints)
        std::cout << "ScavTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->energyPoints)
        std::cout << "ScavTrap " << this->name << " has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    return ;
}

void    ScavTrap::guardGate(void){

    if (!this->hitPoints)
        std::cout << "ScavTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " is now in gatekeeping mode" <<std::endl;
    return ;
}
