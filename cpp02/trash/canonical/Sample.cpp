#include "Sample.hpp"
 
Sample::Sample(void) : _foo(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}
 
Sample::Sample(int const n) : _foo(n)
{
    std::cout << "Parametric constructor called" << std::endl;
    return ;
}

Sample::Sample(Sample const & src) : _foo(src.getValue())
{
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Sample::~Sample(void)
{
    std::cout << "Default destructor called" << std::endl; 
}

int     Sample::getValue(void) const{

    return this->_foo;
}

Sample& Sample::operator=(Sample const & rhs){

    std::cout << "Assignation operator call from " << this->_foo;
    std::cout << " to " << rhs.getValue() << std::endl;
    this->_foo = rhs.getValue();
    return *this;
}

std::ostream & operator<<(std::ostream & o, Sample const & rhs){

    o << rhs.getValue();
    return  o;
}

