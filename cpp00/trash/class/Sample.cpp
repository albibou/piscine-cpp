#include <iostream>
#include "Sample.hpp"

Sample::Sample(void){

    std::cout << "Constructor has been called" << std::endl;
    return ;
}

Sample::~Sample(void){

    std::cout << "Destructor has been called" << std::endl;
    return ;
}
