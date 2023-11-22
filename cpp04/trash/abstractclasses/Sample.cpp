#include "Sample.hpp"

Aabstract::Aabstract(void){
 
    std::cout << "Aabstract Default Constructor" << std::endl;
    return ;
}

Aabstract::~Aabstract(void){
 
    std::cout << "Aabstract Default Destructor" << std::endl;
   return ;
}

void    Aabstract::sayGoodbye(void){

    std::cout << "Goodbye" << std::endl;
}

Iinterface::Iinterface(void){
 
    std::cout << "Iinterface Default Constructor" << std::endl;
    return ;
}

Iinterface::~Iinterface(void){
 
    std::cout << "Iinterface Default Constructor" << std::endl;
   return ;
}

Sample::Sample(void){
 
    std::cout << "Sample Default Constructor" << std::endl;
    return ;
}
 
Sample::~Sample(void){
 
    std::cout << "Sample Default Constructor" << std::endl;
   return ;
}

void    Sample::sayCheers(void){
    std::cout << "Cheers" <<std::endl;
}

void    Sample::sayYes(void){
    std::cout << "Yes" <<std::endl;
}
void    Sample::sayHello(void){
    std::cout << "Hello" <<std::endl;
}
