#include "WrongCat.hpp"
 
WrongCat::WrongCat(void) : WrongAnimal("WrongCat"){
 
    std::cout << "Default WrongCat Constructor Called" << std::endl;
    return ;
}
 
WrongCat::WrongCat(WrongCat const & src){
 
    *this = src;
    std::cout << "Copy WrongCat Constructor Called" << std::endl;
    return ;
}
 
WrongCat::~WrongCat(void){
 
    std::cout << "Default WrongCat Destructor Called" << std::endl;
    return ;
}
 
WrongCat & WrongCat::operator=(WrongCat const & rhs){
 
   this->type = rhs.type;
   return *this;
}

void    WrongCat::makeSound(void) const{

    std::cout << "'Woof Woof'" << std::endl;
    return ;
}

