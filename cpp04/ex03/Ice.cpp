#include "Ice.hpp"
 
Ice::Ice(void) : AMateria("ice"){
 
    std::cout << "Default Ice Constructor called" << std::endl; 
    return ;
}
 
Ice::Ice(Ice const & src){
 
    *this = src;
    std::cout << "Copy Ice Constructor called" << std::endl; 
    return ;
}
 
Ice::~Ice(void){
 
    std::cout << "Default Ice Destructor called" << std::endl; 
    return ;
}
 
Ice & Ice::operator=(Ice const & rhs){
 
    this->type = rhs.type;
    return *this;
}

Ice*    Ice::clone(void) const{

    Ice *clone = new Ice();
    *clone = *this;
    return clone;
}

void    Ice::use(ICharacter& target){

    std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl;
    return ;
}
