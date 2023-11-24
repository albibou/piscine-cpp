#include "ICharacter.hpp"
 
ICharacter::ICharacter(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
ICharacter::ICharacter(ICharacter const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
ICharacter::~ICharacter(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
ICharacter & ICharacter::operator=(ICharacter const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


