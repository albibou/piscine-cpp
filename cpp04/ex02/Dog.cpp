#include "Dog.hpp"

Dog::Dog(void) : Aanimal("Dog"){
 
    _brain = new Brain[100];
    std::cout << "Default Dog Constructor Called" << std::endl;
    return ;
}
 
Dog::Dog(Dog const & src){
 
    *this = src;
    std::cout << "Copy Dog Constructor Called" << std::endl;
    return ;
}
 
Dog::~Dog(void){
 
    delete[] _brain;
    std::cout << "Default Dog Destructor Called" << std::endl;
    return ;
}
 
Dog & Dog::operator=(Dog const & rhs){
 
   this->type = rhs.type;
   this->_brain = new Brain[100];
   this->_brain = rhs._brain;
   return *this;
}

void    Dog::makeSound(void) const{

    std::cout << "'Woof, woof'" << std::endl;
    return ;
}

void    Dog::fillIdea(std::string idea, int index){

    if (index < 1 || index > 100)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    this->_brain->ideas[index - 1] = idea;
    return ;
}

void    Dog::displayIdeas(void) const{

    for (int i = 0; i < 100; i++)
        this->displayanIdea(i);
    return ;
}

void    Dog::displayanIdea(int index) const{
    
    if (index < 0 || index > 99)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    std::cout << std::endl << "Idea n " << index + 1 << " " << this->_brain->ideas[index] << std::endl << std::endl; 
    return;
}
