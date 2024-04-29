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

std::ostream & operator<<(std::ostream & o, Span const & rhs){

  for(std::set<int>::const_iterator it = rhs.getSet().begin(); it != rhs.getSet().end(); it++)
    o << *it << std::endl;
  return o;
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

const std::set<int> & Span::getSet(void) const{

  return _numbers;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void  Span::addNumber(int number){

  if (_numbers.size() >= _maxCapacity)
    throw Span::TooManyNumbers();
  _numbers.insert(number);
}

unsigned int  Span::shortestSpan(void){

  if (getSize() < 2)
    throw Span::NotEnoughNumbers();

  std::set<int>::const_iterator it = _numbers.begin();
  unsigned int shortestSpan = *(_numbers.upper_bound(*it)) - *it;
  for (std::set<int>::const_iterator it = _numbers.begin(); it != --(_numbers.end()); it++){
    if (static_cast<unsigned int>(*(_numbers.upper_bound(*it)) - *it) < shortestSpan)
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
