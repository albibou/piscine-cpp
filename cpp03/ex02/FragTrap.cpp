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
 
FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src){
 
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

void    FragTrap::highFivesGuys(void){
        
    if (!this->hitPoints)
        std::cout << "FragTrap " << this->name << " has no hit points left and is incounscious." << std::endl;
    else
        std::cout << "FragTrap " << this->name << ": please sisters and brothers of inheritance, give me a high five !!!" <<std::endl;
    return ;
}
