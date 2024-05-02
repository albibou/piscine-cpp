#ifndef CLASS_H
# define CLASS_H

# include <iostream>
# include <string>
# include <map>
# include <limits>
# include <algorithm>
# include <fstream>
# include <cstdlib>

# ifndef PRINT
#  define PRINT 0
# endif

# define DATABASENAME "data.csv"
# define DATABASEFILE 0
# define INPUTFILE 1

class BitcoinExchange{

  public :

    BitcoinExchange(void);
    BitcoinExchange(BitcoinExchange const & rhs);
    ~BitcoinExchange(void);

    BitcoinExchange & operator=(BitcoinExchange const & rhs);


  private :

    std::map<std::string, double> _dataset;

    void  set_database(void);
    void  check_input_file(std::ifstream & file, int type) const;
    void  parse_input_file(std::ifstream & db_file);
    bool  date_is_valid(std::string const & date) const;
    bool  btc_value_is_valid(std::string const & value) const;

    class FileNotOpen : public std::exception{
      const char * what() const throw();
    }; 
    class FileIsEmpty : public std::exception{
      const char * what() const throw();
    }; 
    class WrongDatabaseHeader : public std::exception{
      const char * what() const throw();
    }; 
    class WrongInputfileHeader : public std::exception{
      const char * what() const throw();
    }; 
   class BadInputInDatabase : public std::exception{
      const char * what() const throw();
    }; 

};

std::ostream & operator<<(std::ostream & o, BitcoinExchange const & rhs);

#endif
