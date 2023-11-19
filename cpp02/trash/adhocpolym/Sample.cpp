#include "Sample.hpp"
 
Sample::Sample()
{
    std::cout << "Constructor called" << std::endl; 
    return ;
}
 
 
Sample::~Sample()
{
    std::cout << "Destructor called" << std::endl; 
    return ;
}

void    Sample::test(char const c) const{

    std::cout << "Surcharge de la fonction avec c = " << c << std::endl;
}

void    Sample::test(int const i) const{

    std::cout << "Surcharge de la fonction avec i = " << i << std::endl;
}

void    Sample::test(float const f) const{

    std::cout << "Surcharge de la fonction avec f = " << f << std::endl;
}

void    Sample::test(Sample const &y) const{

    (void)y;
    std::cout << "Surcharge de la fonction avec une ref de l'instance " << std::endl;
}
