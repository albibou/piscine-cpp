#include "Cat.hpp"
 
Cat::Cat(void) : Animal("Cat"){
 
    std::cout << "Default Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::Cat(Cat const & src){
 
    *this = src;
    std::cout << "Copy Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::~Cat(void){
 
    std::cout << "Default Cat Destructor Called" << std::endl;
    return ;
}
 
Cat & Cat::operator=(Cat const & rhs){
 
   this->type = rhs.type;
   return *this;
}

void    Cat::makeSound(void) const{

    std::cout << "'Meow'" << std::endl;
    return ;
}
