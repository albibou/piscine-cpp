#include <iostream>
#include "Sample.hpp"

void    f0(void)
{
    Sample  instance;
    std::cout << "nbInst = " << Sample::get_nbInst() << std::endl;

    return ;
}

void    f1(void)
{
    Sample  instance;
    std::cout << "nbInst = " << Sample::get_nbInst() << std::endl;
    f0();

    return ;
}


int main(void){

    std::cout << "nbInst = " << Sample::get_nbInst() << std::endl;
    f1();
    std::cout << "nbInst = " << Sample::get_nbInst() << std::endl;

    return (0);
}
