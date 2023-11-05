#include <iostream>
#include "Sample.hpp"

int main(void){

    Sample  instance;
    Sample  *instancep = &instance;

    int Sample::*p = &Sample::foo;
    void    (Sample::*f)(void) const = &Sample::bar;

    std::cout << "Foo =" << instance.foo << std::endl;

    /*Example 01*/

    instance.foo = 21;
    std::cout << "Foo =" << instance.foo << std::endl;
    instancep->foo = 42;
    std::cout << "Foo =" << instance.foo << std::endl;

    /*Example 02*/

    instance.*p = 63;
    std::cout << "Foo =" << instance.foo << std::endl;
    instancep->*p = 84;
    std::cout << "Foo =" << instance.foo << std::endl;

    /*Example 03*/

    (instance.*f)();
    (instancep->*f)();

    return (0);
}
