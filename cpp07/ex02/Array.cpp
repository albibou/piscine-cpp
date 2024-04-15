#include "Array.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

Array::Array(void){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

Array::Array(Array const & rhs){

  (void)rhs;
  //insert assignation
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

Array::~Array(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

Array & Array::operator=(Array const & rhs){

  if (this != &rhs) 
  {
    //insert assignation
  }
  (void)rhs;
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

std::ostream & operator<<(std::ostream & o, Array const & rhs){

  (void)rhs;
  /*o << insert output desired*/;
  return o;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

