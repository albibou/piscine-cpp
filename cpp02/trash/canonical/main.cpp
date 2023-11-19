#include "Sample.hpp"

int main(void){

    Sample  instance;
    Sample  instance2(42);
    Sample  instance3(instance);

    std::cout << "Value of instance : " << instance << std::endl;
    std::cout << "Value of instance2 : " << instance2 << std::endl;
    std::cout << "Value of instance3 : " << instance3 << std::endl;

    instance3 = instance2;

    std::cout << "Value of instance3 :" << instance3 <<std::endl;
    return(0);
}
