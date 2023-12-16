/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:57:19 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:57:20 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
 
FragTrap::FragTrap(void){
 
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Default FragTrap Constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
 
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Parametric FragTrap Constructor called" << std::endl;
    return ;
}
 
FragTrap::FragTrap(FragTrap const & src){
 
    *this = src;
    std::cout << "Copy FragTrap Constructor called" << std::endl;
    return ;
}
 
FragTrap::~FragTrap(void){
 
    std::cout << "Default FragTrap Destructor called" << std::endl;
   return ;
}
 
FragTrap & FragTrap::operator=(FragTrap const & rhs){
 
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
   return *this;
}

void    FragTrap::attack(const std::string& target){

    if (!this->hitPoints)
        std::cout << "FragTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->energyPoints)
        std::cout << "FragTrap " << this->name << " has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    return ;
}

void    FragTrap::takeDamage(unsigned int amount){

    if (amount > this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "FragTrap " << this->name << " has no hit points left and fall incounscious" << std::endl;
        return ;
    }
    this->hitPoints -= amount;
    std::cout << "FragTrap " << this->name << " is attacked, causing " << amount << " points of damage! He has " << this->hitPoints << " left" << std::endl;
    return ;
}

void    FragTrap::beRepaired(unsigned int amount){
      
    if (!this->hitPoints)
        std::cout << "FragTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->energyPoints)
        std::cout << "FragTrap " << this->name << " has no energy points left and can't do anything" << std::endl;
    else 
    {
        std::cout << "FragTrap " << this->name << " repairs itself and get " << amount << " hit points back, for a total of " << this->hitPoints + amount << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    }
    return ;
}

void    FragTrap::highFivesGuys(void){
        
    if (!this->hitPoints)
        std::cout << "FragTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else if (!this->energyPoints)
        std::cout << "FragTrap " << this->name << " has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->name << ": please sisters and brothers of inheritance, give me a high five !!!" <<std::endl;
        this->energyPoints--;
    }
    return ;
}
