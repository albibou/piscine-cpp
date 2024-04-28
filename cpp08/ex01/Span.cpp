#include "Span.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

Span::Span(void) : _maxCapacity(0){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

Span::Span(const unsigned int N) : _maxCapacity(N){

  if (PRINT)
    std::cout << "Parametric constructor called" << std::endl;
  return ;
} 

Span::Span(Span const & rhs){

  this->_maxCapacity = rhs._maxCapacity;
  this->_numbers = rhs._numbers;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

Span::~Span(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

Span & Span::operator=(Span const & rhs){

  if (this != &rhs) 
  {
    this->_maxCapacity = rhs._maxCapacity;
    this->_numbers = rhs._numbers;
  }
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

unsigned int  Span::getSize(void) const{

  return this->_numbers.size();
}

unsigned int  Span::getMaxCapacity(void) const{

  return this->_maxCapacity;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void  Span::addNumber(int number){

  if (_numbers.size() >= _maxCapacity)
    throw Span::TooManyNumbers();
  _numbers.insert(number);
}

template <typename Iterator>
void  Span::addManyNumbers(Iterator begin, Iterator end){

  for (Iterator it = begin; it != end; it++)
    addNumber(*it);
}

unsigned int  Span::shortestSpan(void){

  if (getSize() < 2)
    throw Span::NotEnoughNumbers();

  std::set<int>::const_iterator it = _numbers.begin();
  int shortestSpan = *(_numbers.upper_bound(*it)) - *it;
  for (std::set<int>::const_iterator it; ++it != _numbers.end(); it++){
    if (*(_numbers.upper_bound(*it)) - *it < shortestSpan)
      shortestSpan = *(_numbers.upper_bound(*it)) - *it;
  }
  return shortestSpan;
}

unsigned int Span::longestSpan(void){

  if (getSize() < 2)
    throw Span::NotEnoughNumbers();
  return (*_numbers.rbegin() - *_numbers.begin());
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  Span::TooManyNumbers::what() const throw() {

  return "The container is already full with numbers";
}

const char *  Span::NotEnoughNumbers::what() const throw() {

  return "The container must contain two numbers minimum";
}
