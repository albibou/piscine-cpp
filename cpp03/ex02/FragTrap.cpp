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
    std::cout << "Default FragTrap Constructor called" << std::endl;
    return ;
}
 
FragTrap::FragTrap(FragTrap const & src){
 
    *this = src;
    std::cout << "Default FragTrap Constructor called" << std::endl;
    return ;
}
 
FragTrap::~FragTrap(void){
 
    std::cout << "Default FragTrap Constructor called" << std::endl;
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
        std::cout << "FragTrap " << this->name << "has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    return ;
}

void    FragTrap::takeDamage(unsigned int amount){

    std::cout << "FragTrap " << this->name << " is attacked, causing " << amount << " points of damage!" << std::endl;
    this->hitPoints -= amount;
    return ;
}

void    FragTrap::beRepaired(unsigned int amount){

    if (this->energyPoints)
    {
        std::cout << "FragTrap " << this->name << " repairs itself and get " << amount << " hit points back, for a total of " << this->hitPoints + amount << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    }
    else
        std::cout << "FragTrap " << this->name << "has no energy points left and can't do anything" << std::endl;
    return ;
}

void    FragTrap::highFivesGuys(void){
    
    if (!energyPoints)
        return (void)(std::cout << "FragTrap " << this->name << "has no energy points left and can't do anything" << std::endl);
    std::cout << "FragTrap " << this->name << " please siters and brothers of inheritance, give me a high five !!!" <<std::endl;
    this->energyPoints--;
    return ;
}
