#include <iostream>
#include "Sample.hpp"

Sample::Sample(void){

    std::cout << "Constructor Called" << std::endl;
    return ;
}

Sample::~Sample(void){

    std::cout << "Destructor Called" << std::endl;
    return ;
}

void    Sample::bar(void){

    std::cout << "bar function Called" << std::endl;
    return ;
}
