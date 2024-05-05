#include "RPN.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

RPN::RPN(void) : _must_be_space(false){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

RPN::RPN(RPN const & rhs){

  *this = rhs;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

RPN::~RPN(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

RPN & RPN::operator=(RPN const & rhs){

  if (this != &rhs) 
  {
    while (this->_stack.size() > 0)
      this->_stack.pop();
    this->_stack = rhs._stack;
    this->_must_be_space = rhs._must_be_space;
    this->_error.flush();
    this->_error << rhs.get_error();
  }
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

std::string RPN::get_error(void) const{

  return this->_error.str();
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

std::string  RPN::get_faulty_operation(char const op, int operand1, int operand2){

  std::stringstream op1_stream;
  std::stringstream op2_stream;
  
  op1_stream << operand1;
  op1_stream << operand2;

  return (op1_stream.str() + " " + op + " " + op2_stream.str());
}

bool  RPN::do_operation(char const op){

  double  result;

  int operand1 = _stack.top();
  _stack.pop();
  int operand2 = _stack.top();
  _stack.pop();
  if ((!operand1 || !operand2) && op == '/')
    return (_error << ZERO_DIVISION, false);
switch (op){
    case '+':
      result = operand2 + operand1;
      break ;
    case '-':
      result = operand2 - operand1;
      break ;
    case '*':
      result = operand2 * operand1;
      break ;
    case '/':
      result = operand2 / operand1;
      break ;
  }
  if (std::abs(result) < std::numeric_limits<int>::min() || std::abs(result) > std::numeric_limits<int>::max())
    return (_error << get_faulty_operation(op, operand1, operand2) << OPERATION_OVERFLOW, false);
  _stack.push(static_cast<int>(std::abs(result)));
  return true;
}

bool  RPN::is_operand(char const value) {

  if (!isdigit(value))
    return false;
  _must_be_space = true;
  return true;
}

bool  RPN::is_operator(char const value) {

  if (value != '+' && value != '-' && value != '*' && value != '/') 
    return false;
  _must_be_space = true;
  return true;
}

bool  RPN::calculate_RPN(std::string const & litteral){

  for (size_t i = 0; i < litteral.size(); i++){

    if (_must_be_space && litteral[i] != ' ')
      return (_error << SPACES, false);
    else if (is_operand(litteral[i]))
      _stack.push(litteral[i] - '0');
    else if (is_operator(litteral[i])){
      if (_stack.size() < 2)
        return (_error << STACK_TOO_SMALL, false);
      if (!do_operation(litteral[i]))
        return false;
    }
    else if (_must_be_space && litteral[i] == ' ')
      _must_be_space = false;
    else if (litteral[i] != ' ')
      return (_error << BAD_CHARACTER_ERROR, false);
  }
  if (_stack.size() != 1)
    return (_error << REST_OPERAND, false);
  std::cout << _stack.top() << std::endl;
  return true;
}
