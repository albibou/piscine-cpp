#include "ScalarConverter.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter(void){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

ScalarConverter::ScalarConverter(ScalarConverter const & rhs){

  (void)rhs;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

ScalarConverter::~ScalarConverter(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){

 (void)rhs;
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

bool ScalarConverter::is_char(std::string const & litteral){

  char  c = litteral.c_str()[0];
  if (litteral.size() == 1 && !isdigit(c))
    return true;
  return false;
}

bool ScalarConverter::is_printable(const char c){

  if (c < 32 || c > 126)
    return false;
  return true;
}

void ScalarConverter::handle_char(std::string const & litteral){
  
  char c = litteral.c_str()[0];
  std::ostringstream o;

  if (!is_printable(c))
    std::cout << CHAR << "Non displayable" << std::endl;
  std::cout << CHAR << c << std::endl;
  std::cout << INT << static_cast<int>(c) << std::endl;
  o << std::setprecision(1);
  o << std::setiosflags(std::ios::fixed);
  o << FLOAT << static_cast<float>(c) << "f" << std::endl;
  o << DOUBLE << static_cast<double>(c) << std::endl;
  std::cout << o.str();
  return ;
}

bool ScalarConverter::is_pseudo_litteral(std::string const & litteral){

  if (litteral == "-inff" || litteral == "+inff" || litteral == "nanf")
    return true;
  else if (litteral == "-inf" || litteral == "+inf" || litteral == "nan")
    return true;
  return false ;
}

void  ScalarConverter::handle_pseudo_litteral(std::string const & litteral){

  std::cout << CHAR << IMPOSSIBLE << std::endl;
  std::cout << INT << IMPOSSIBLE << std::endl;
  if (litteral == "-inff" || litteral == "+inff" || litteral == "nanf"){
    std::cout << FLOAT << litteral << std::endl;
    std::cout << DOUBLE << litteral.substr(0, litteral.length() - 1) << std::endl;
  }
  else if (litteral == "-inf" || litteral == "+inf" || litteral == "nan"){
    std::cout << FLOAT << litteral << "f" << std::endl;
    std::cout << DOUBLE << litteral << std::endl;
  }
  return ;
}

bool  ScalarConverter::is_int(std::string const & litteral, std::string const & res){
  
  if (!litteral.empty() && res.empty() && litteral.find(".") == std::string::npos)
    return true ;
  return false ;
}

void  ScalarConverter::handle_int(long double num, std::string const & litteral){

  std::stringstream o;
  char *buffer = NULL;
  int i = strtol(litteral.c_str(), &buffer, 10);

  if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max()){
    if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max()){
      if (is_printable(static_cast<char>(i)))
        std::cout << CHAR << static_cast<char>(i) << std::endl;
      else
        std::cout << CHAR << "Non displayable" << std::endl;
    }
    else
      std::cout << CHAR << IMPOSSIBLE << std::endl;
    std::cout << INT << i << std::endl;
    o << std::setprecision(1);
    o << std::setiosflags(std::ios::fixed);
    o << FLOAT << static_cast<float>(i) << "f" << std::endl;
    o << DOUBLE << static_cast<double>(i) << std::endl;
    std::cout << o.str();
  }
  else {
    std::cout << CHAR << "Int over/underflow, impossible" << std::endl;
    std::cout << INT << "Int over/underflow, impossible" << std::endl;
    std::cout << FLOAT << "Int over/underflow, impossible" << std::endl;
    std::cout << DOUBLE << "Int over/underflow, impossible" << std::endl;
  }
  return ;
}

bool  ScalarConverter::is_float(std::string const & litteral, std::string const & res){
  
  if (!litteral.empty() && (res == "f" || res == "F") && litteral.find(".") != std::string::npos)
    return true ;
  return false ;
}

void  ScalarConverter::handle_float(long double num, std::string const & litteral){

  std::stringstream o;
  char *buffer = NULL;
  float f = strtof(litteral.c_str(), &buffer);

  if (std::abs(num) >= -std::numeric_limits<float>::max() && std::abs(num) <= std::numeric_limits<float>::max()){
    if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max()){
      if (is_printable(static_cast<char>(f)))
        std::cout << CHAR << static_cast<char>(f) << std::endl;
      else
        std::cout << CHAR << "Non displayable" << std::endl;
    }
    else
      std::cout << CHAR << IMPOSSIBLE << std::endl;
    if (std::abs(f) >= std::numeric_limits<int>::min() && std::abs(f) <= std::numeric_limits<int>::max())
      std::cout << INT << static_cast<int>(f) << std::endl;
    else 
      std::cout << INT << IMPOSSIBLE << std::endl;
    o << std::setprecision(litteral.size() - 2 - litteral.find("."));
    o << std::setiosflags(std::ios::fixed);
    o << FLOAT << f << "f" << std::endl;
    o << DOUBLE << static_cast<double>(f) << std::endl;
    std::cout << o.str();
  }
  else {
    std::cout << CHAR << "Float over/underflow, impossible" << std::endl;
    std::cout << INT << "Float over/underflow, impossible" << std::endl;
    std::cout << FLOAT << "Float over/underflow, impossible" << std::endl;
    std::cout << DOUBLE << "Float over/underflow, impossible" << std::endl;
  }
  return ;
}

bool  ScalarConverter::is_double(std::string const & litteral, std::string const & res){
  
  if (!litteral.empty() && res.empty() && litteral.find(".") != std::string::npos)
    return true ;
  return false ;
}

void  ScalarConverter::handle_double(long double num, std::string const & litteral){

  std::stringstream o;
  double d = static_cast<double>(num);

  if (std::abs(num) >= -std::numeric_limits<double>::max() && std::abs(num) <= std::numeric_limits<double>::max()){
    if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max()){
      if (is_printable(static_cast<char>(d)))
        std::cout << CHAR << static_cast<char>(d) << std::endl;
      else
        std::cout << CHAR << "Non displayable" << std::endl;
    }
    else
      std::cout << CHAR << IMPOSSIBLE << std::endl;
    if (std::abs(d) >= std::numeric_limits<int>::min() && std::abs(d) <= std::numeric_limits<int>::max())
      std::cout << INT << static_cast<int>(d) << std::endl;
    else 
      std::cout << INT << IMPOSSIBLE << std::endl;
    o << std::setprecision(litteral.size() - 1 - litteral.find("."));
    o << std::setiosflags(std::ios::fixed);
    if (std::abs(static_cast<float>(d)) >= std::numeric_limits<float>::min() && std::abs(static_cast<float>(d)) <= std::numeric_limits<float>::max())
      o << FLOAT << static_cast<float>(d) << "f" << std::endl;
    else 
      std::cout << FLOAT << IMPOSSIBLE << std::endl;
    o << DOUBLE << d << std::endl;
    std::cout << o.str();
  }
  else {
    std::cout << CHAR << "Double over/underflow, impossible" << std::endl;
    std::cout << INT << "Double over/underflow, impossible" << std::endl;
    std::cout << FLOAT << "Double over/underflow, impossible" << std::endl;
    std::cout << DOUBLE << "Double over/underflow, impossible" << std::endl;
  }
  return ;
}

void  ScalarConverter::handle_impossible(void){

  std::cout << CHAR << IMPOSSIBLE << std::endl;
  std::cout << INT << IMPOSSIBLE << std::endl;
  std::cout << FLOAT << IMPOSSIBLE << std::endl;
  std::cout << DOUBLE << IMPOSSIBLE << std::endl;
  return ;
}

void  ScalarConverter::convert(std::string const & litteral){

  if (is_pseudo_litteral(litteral))
    return handle_pseudo_litteral(litteral);
  else if (is_char(litteral))
    return handle_char(litteral);
  char  *tmp = NULL;
  long double num = strtold(litteral.c_str(), &tmp);
  std::string res(tmp);
  if (is_int(litteral, res))
    return handle_int(num, litteral);
  else if (is_float(litteral, res))
    return handle_float(num, litteral);
  else if (is_double(litteral, res))
    return handle_double(num, litteral);
  else 
    return handle_impossible();
}
