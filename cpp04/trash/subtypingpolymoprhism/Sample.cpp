#include "Sample.hpp"
 
Sample::Sample(void){
 
    return ;
}
 
Sample::~Sample(void){
 
   return ;
}
 

void  Sample::greet(std::string value) {

    std::cout << "Hello " << value << ". Ca va le sang ?" << std::endl;
    return ;
}

void  Sample::ungreet(std::string value) {

    std::cout << "See you soon " << value << " !" << std::endl;
    return ;
}
