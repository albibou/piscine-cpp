/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:03:07 by atardif           #+#    #+#             */
/*   Updated: 2024/05/31 14:03:09 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# include <iostream>
# include <iomanip>
# include <string>
# include <map>
# include <limits>
# include <algorithm>
# include <fstream>
# include <sstream>
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

    void  exchange(std::string const file_name) const;
    void  print_data_set(void)const;

  private :

    std::map<std::string, double> _dataset;

    void  set_database(void);
    void  check_input_file(std::ifstream & file, int type) const;
    void  parse_data_file(std::ifstream & db_file);
    bool  date_is_valid(std::string const & date) const;
    bool  get_token_date(std::string const & token_litteral, double *token_value) const;
    bool  is_leap_year(double year) const;
    bool  btc_value_is_valid(std::string const & value) const;

    void  parse_input_file(std::ifstream & input_file) const;
    bool  amount_value_is_valid(std::string const & value, std::string const & line) const;
    bool  get_previous_date(std::string & date) const;
    bool  get_value_from_date(std::string & date, double * btc_value) const;
    size_t  get_precision_from_value(double btc_value) const;

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
