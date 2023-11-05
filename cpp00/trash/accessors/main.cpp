#include <iostream>
#include "Sample.hpp"

int main(void){

    Sample  instance;

    std::cout << "get_foo =" << instance.get_foo() << std::endl;
    instance.set_foo(1000);
    std::cout << "get_foo =" << instance.get_foo() << std::endl;
    instance.set_foo(-1000);
    std::cout << "get_foo =" << instance.get_foo() << std::endl;

    return (0);
}
