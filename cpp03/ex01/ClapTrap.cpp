#include "ClapTrap.hpp"
 
ClapTrap::ClapTrap(void) : name("default"), hitPoints(10), energyPoints(10), attackDamage(0){
     
    std::cout << "Default ClapTrap constructor called" << std::endl;
    return ;
}
 
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
     
    std::cout << "Parametric ClapTrap constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const & src){

    *this = src;
    std::cout << "Copy ClapTrap Constructor called" << std::endl;
    return ;
}
 
ClapTrap::~ClapTrap(void){
 
    std::cout << "Default ClapTrap destructor called" << std::endl;
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
        std::cout << "ClapTrap " << this->name << "has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount){

    std::cout << "ClapTrap " << this->name << " is attacked, causing " << amount << " points of damage!" << std::endl;
    this->hitPoints -= amount;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount){

    if (this->energyPoints)
    {
        std::cout << "ClapTrap " << this->name << " repairs itself and get " << amount << " hit points back, for a total of " << this->hitPoints + amount << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->name << "has no energy points left and can't do anything" << std::endl;
    return ;
}
