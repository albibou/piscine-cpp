#include "IMateriaSource.hpp"
 
IMateriaSource::IMateriaSource(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
IMateriaSource::IMateriaSource(IMateriaSource const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
IMateriaSource::~IMateriaSource(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
IMateriaSource & IMateriaSource::operator=(IMateriaSource const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


