#include "MateriaSource.hpp"
 
MateriaSource::MateriaSource(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
MateriaSource::MateriaSource(MateriaSource const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
MateriaSource::~MateriaSource(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
MateriaSource & MateriaSource::operator=(MateriaSource const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


