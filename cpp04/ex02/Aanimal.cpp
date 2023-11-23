#include "Aanimal.hpp"
 
Aanimal::Aanimal(void) : type("Default"){
 
    std::cout << "Default Aanimal Constructor Called" << std::endl;
    return ;
}
 
Aanimal::Aanimal(std::string name) : type(name){
 
    std::cout << "Type Aanimal Constructor Called" << std::endl;
    return ;
}

Aanimal::Aanimal(Aanimal const & src){
 
    *this = src;
    std::cout << "Copy Aanimal Constructor Called" << std::endl;
    return ;
}
 
Aanimal::~Aanimal(void){
 
    std::cout << "Default Aanimal Destructor Called" << std::endl;
    return ;
}
 
Aanimal & Aanimal::operator=(Aanimal const & rhs){
 
   this->type = rhs.type;
   return *this;
}

std::string Aanimal::getType(void) const{

    return this->type;
}

void    Aanimal::makeSound(void) const{

    std::cout << "'Aanimal noiiiise'" << std::endl;
    return ;
}

