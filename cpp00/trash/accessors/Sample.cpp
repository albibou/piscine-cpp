#include <iostream>
#include "Sample.hpp"

Sample::Sample(void){

    std::cout << "Constructor called" << std::endl;
    this->_foo=42;

    return ;
}

Sample::~Sample(void){

    std::cout << "Destructor called" << std::endl;

    return ;
}

int Sample::get_foo(void) const{

    return this->_foo;
}

void    Sample::set_foo(int i){

    if (i >= 0)
        this->_foo = i;

    return ;
}
