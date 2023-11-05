#include <iostream>
#include "Sample.hpp"

int main(void){

    Sample  instance1(42);
    Sample  instance2(-42);

    if (&instance1 == &instance1)
        std::cout << "Instances are physically equal" << std::endl;
    else
        std::cout << "Instances are not physically equal" << std::endl;

    if (&instance1 == &instance2)
        std::cout << "Instances are physically equal" << std::endl;
    else
        std::cout << "Instances are not physically equal" << std::endl;

    if (instance1.compare(&instance1))
        std::cout << "Instances are structurally equal" << std::endl;
    else
        std::cout << "Instances are not structurally equal" << std::endl;

    if (instance1.compare(&instance2))
        std::cout << "Instances are structurally equal" << std::endl;
    else
        std::cout << "Instances are not structurally equal" << std::endl;

    return (0);
}
