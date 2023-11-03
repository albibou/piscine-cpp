#include <iostream>
#include "Sample.hpp"

int main(void){
    
    Sample instance;

    std::cout << std::endl << "In the main" << std::endl;
    instance.public_foo = 42;
    instance.public_bar();
    std::cout << "instance->publicFoo =" << instance.public_foo << std::endl;

    //instance._private_foo = 42;
    //instance._private_bar();
    //std::cout << "instance._privateFoo =" << instance._private_foo << std::endl;
    //
    return (0);
}
