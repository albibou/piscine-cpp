/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:54:46 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:02:42 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
 
ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
     
    std::cout << "Default ClapTrap Constructor called" << std::endl;
    return ;
}
 
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
     
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

    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void    ClapTrap::attack(const std::string& target){

    if (!this->_hitPoints)
        std::cout << "ClapTrap " << this->_name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->_energyPoints)
        std::cout << "ClapTrap " << this->_name << " has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount){

    if (amount > this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " has no hit points left and fall incounscious" << std::endl;
        return ;
    }
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " is attacked, causing " << amount << " points of damage! He has " << this->_hitPoints << " left" << std::endl;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount){
    
    if (!this->_hitPoints)
        std::cout << "ClapTrap " << this->_name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->_energyPoints)
        std::cout << "ClapTrap " << this->_name << " has no energy points left and can't do anything" << std::endl;
    else 
    {
        std::cout << "ClapTrap " << this->_name << " repairs itself and get " << amount << " hit points back, for a total of " << this->_hitPoints + amount << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }
    return ;
}
