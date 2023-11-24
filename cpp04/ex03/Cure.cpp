#include "Cure.hpp"
 
Cure::Cure(void) : AMateria("cure"){
 
    std::cout << "Default Cure Constructor called" << std::endl; 
    return ;
}
 
Cure::Cure(Cure const & src){
 
    std::cout << "Copy Cure Constructor called" << std::endl; 
    return ;
}
 
Cure::~Cure(void){
 
    std::cout << "Default Cure Destructor called" << std::endl; 
    return ;
}
 
Cure & Cure::operator=(Cure const & rhs){
 
    this->type = rhs.type;
    //this->default = rhs->default;
    return *this;
}

Cure*    Cure::clone(void) const{

    Cure *clone = new Cure();
    *clone = *this;
    return clone;
}

void    Cure::use(ICharacter& target){

    std::cout << "* heals " << target.name << " 's wounds *" << std::endl;
    return ;
}
