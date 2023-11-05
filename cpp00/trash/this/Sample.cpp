#include <iostream> 
#include "Sample.hpp"

Sample::Sample(void){

    std::cout << "Constructotr is called" << std::endl;
    this->foo = 42;
    std::cout << "this->foo =" << this->foo << std::endl;
    this->bar();
    return ;
}

Sample::~Sample(void){

    std::cout << "Destructor is called" << std::endl;
    return ;
}

void    Sample::bar(void)
{
    std::cout << "bar function called" << std::endl;
    return ;
}
