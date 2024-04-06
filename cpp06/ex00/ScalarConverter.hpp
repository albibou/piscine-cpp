#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <sstream>

# ifndef PRINT
#  define PRINT 0
# endif

# define CHAR "char : "
# define INT "int : "
# define FLOAT "float : "
# define DOUBLE "double : "
# define IMPOSSIBLE "impossible"

class ScalarConverter{

  public :

   ~ScalarConverter(void);

   static void convert(std::string const & litteral);

  private :

    ScalarConverter(void);
    ScalarConverter(ScalarConverter const & rhs);

    ScalarConverter & operator=(ScalarConverter const & rhs);

    static bool is_char(std::string const & litteral);
    static bool is_printable(const char c);
    static void handle_char(std::string const & litteral);

    static bool is_pseudo_litteral(std::string const & litteral);
    static void  handle_pseudo_litteral(std::string const & litteral);

    static bool  is_int(std::string const & litteral, std::string const & res);
    static void  handle_int(long double num);

    static bool  is_float(std::string const & litteral, std::string const & res);
    static void  handle_float(long double num, std::string const & litteral);

    static bool  is_double(std::string const & litteral, std::string const & res);
    static void  handle_double(long double num, std::string const & litteral);

    static void  handle_impossible(void);
};

std::ostream & operator<<(std::ostream & o, ScalarConverter const & rhs);

#endif
