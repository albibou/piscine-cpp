#include "ClapTrap.hpp"
 
ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
     
    std::cout << "Default constructor called" << std::endl;
    return ;
}
 
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
     
    std::cout << "Parametric constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const & src){

    *this = src;
    std::cout << "Copy Constructor called" << std::endl;
    return ;
}
 
ClapTrap::~ClapTrap(void){
 
    std::cout << "Default destructor called" << std::endl;
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
        std::cout << "ClapTrap " << this->_name << "has no energy points left and can't do anything" << std::endl;
    else
    {
        std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount){

    std::cout << "Claptrap " << this->_name << " is attacked, causing " << amount << " points of damage!" << std::endl;
    this->_hitPoints -= amount;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount){

    if (this->_energyPoints)
    {
        std::cout << "ClapTrap " << this->_name << " repairs itself and get " << amount << " hit points back, for a total of " << this->_hitPoints + amount << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->_name << "has no energy points left and can't do anything" << std::endl;
    return ;
}
