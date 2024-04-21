#ifndef ARRAY_T
# define ARRAY_T

# include "Array.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

template <typename T>
Array<T>::Array(void) : _elements(NULL), _size(0){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

template <typename T>
Array<T>::Array(unsigned int size) : _size(size) {

  _elements = new T[_size];
  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

template <typename T>
Array<T>::Array(Array const & rhs) : _size(rhs._size){

  if (_size){
    this->_elements = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
      this->_elements[i] = rhs._elememts[i];
  }
  else 
    this->_elements = NULL;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

template <typename T>
Array<T>::~Array(void){

  if (this->_elements)
    delete[] this->_elements;
  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs){

  if (this != &rhs) {
    this->_size = rhs._size;
    if (this->_elements)
      delete this->_elements;
    if (this->_size){
      this->_elements = new T[_size];
      for (unsigned int i = 0; i < _size; i++)
        this->_elements[i] = rhs._elements[i];
    }
    else 
      this->_elements = NULL;
  }
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int index) const{

  if (index >= this->_size)
    throw Array<T>::IndexTooBig();
  return this->_elements[index] ;
}
///
////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

template <typename T>
unsigned int Array<T>::size(void)const{

  return (this->_size);
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

template <typename T>
const char * Array<T>::IndexTooBig::what() const throw(){

  return ("This index is out of range");
}

#endif
