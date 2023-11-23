#include "Cat.hpp"
 
Cat::Cat(void) : Aanimal("Cat"){
 
    _brain = new Brain[100];
    std::cout << "Default Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::Cat(Cat const & src){
 
    *this = src;
    std::cout << "Copy Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::~Cat(void){
 
    delete[] _brain;
    std::cout << "Default Cat Destructor Called" << std::endl;
    return ;
}
 
Cat & Cat::operator=(Cat const & rhs){
 
   this->type = rhs.type;
   this->_brain = new Brain[100];
   this->_brain = rhs._brain;
   return *this;
}

void    Cat::makeSound(void) const{

    std::cout << "'Meow'" << std::endl;
    return ;
}

void    Cat::fillIdea(std::string idea, int index){

    if (index < 1 || index > 100)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    this->_brain->ideas[index - 1] = idea;
    return ;
}

void    Cat::displayIdeas(void) const{

    std::cout << std::endl;
    for (int i = 0; i < 100; i++)
        this->displayanIdea(i);
    std::cout << std::endl;
    return ;
}

void    Cat::displayanIdea(int index) const{
    
    if (index < 0 || index > 99)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    std::cout << "Idea n " << index + 1 << " " << this->_brain->ideas[index] << std::endl; 
    return;
}
