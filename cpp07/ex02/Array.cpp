#include "Array.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

Array::Array(void) : _elements = NULL, _size = 0{

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

Array::Array(unsigned int size) : _size = size {

  _elements = new T[n];
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

  for (int i = 0; i < size; i++)
  {
    if (_elements[i])
      delete elements[i];
  }
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


T & Array::operator[](unsigned int index) const{

  return ;
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

unsigned int  size(void)const;

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

