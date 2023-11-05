#include <iostream>
#include "Sample.hpp"

Sample::Sample(int i){

    std::cout << "Constructor called" << std::endl;
    this->_foo = i;

    return ;
}

Sample::~Sample(void){

    std::cout << "Destructor called" << std::endl;

    return ;
}

int     Sample::get_foo(void) const{

    return this->_foo;
}

bool    Sample::compare(Sample *other) const{

    if (other->get_foo() > this->_foo)
        return false;
    else if (other->get_foo() < this->_foo)
        return false;
    return true;
}
