#include <iostream>
#include "Sample.hpp"

Sample::Sample(void){

    std::cout << "Constructor is called" << std::endl;

    this->public_foo = 0;
    std::cout << "this->publicFoo =" << this->public_foo << std::endl;
    this->_private_foo = 0;
    std::cout << "this->_privateFoo =" << this->_private_foo << std::endl;

    this->public_bar();
    this->_private_bar();

    return ;
}

Sample::~Sample(void){

    std::cout << "Destructor is called" << std::endl;
    return ;
}

void    Sample::public_bar(void) const {

    std::cout << "Public Member function called" << std::endl;
    return ;
}

void    Sample::_private_bar(void) const {

    std::cout << "Private Member function called" << std::endl;
    return ;
}
