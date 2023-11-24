#include "Character.hpp"
 
Character::Character(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
Character::Character(Character const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
Character::~Character(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
Character & Character::operator=(Character const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


