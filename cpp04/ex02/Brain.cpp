#include "Brain.hpp"
 
Brain::Brain(void){
 
    //std::cout << "Default Brain contructor called" << std::endl;
    return ;
}
 
Brain::Brain(Brain const & src){
 
    *this = src;
    std::cout << "Copy Brain contructor called" << std::endl;
    return ;
}
 
Brain::~Brain(void){
 
    //std::cout << "Default Brain destructor called" << std::endl;
   return ;
}
 
Brain & Brain::operator=(Brain const & rhs){

    for(int i = 0; i < 100; i++)
        this->ideas[i] = rhs.ideas[i];
   return *this;
}


