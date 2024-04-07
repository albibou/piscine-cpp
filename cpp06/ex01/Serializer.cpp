#include "Serializer.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

Serializer::Serializer(void){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

Serializer::Serializer(Serializer const & rhs){

  (void)rhs;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

Serializer::~Serializer(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

Serializer & Serializer::operator=(Serializer const & rhs){

  if (this != &rhs) 
  {
    //insert assignation
  }
  (void)rhs;
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, Serializer const & rhs){

  (void)rhs;
  return o;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

uintptr_t Serializer::serialize(Data *ptr){

  return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(uintptr_t raw){

  return (reinterpret_cast<Data *>(raw));
}
