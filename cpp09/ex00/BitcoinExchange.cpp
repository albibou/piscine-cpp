/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:02:59 by atardif           #+#    #+#             */
/*   Updated: 2024/05/31 14:03:01 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(void){

  try {
    set_database();
  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs){

  this->_dataset = rhs._dataset;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

BitcoinExchange::~BitcoinExchange(void){

  _dataset.clear();
  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs){

  if (this != &rhs) 
  {
    this->_dataset = rhs._dataset;
  }
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

////////////////////////////////////////////////////////////////////
///                        Getters/Setters                       ///
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

void  BitcoinExchange::check_input_file(std::ifstream & file, int type) const{

  if (!file.is_open())
    throw BitcoinExchange::FileNotOpen();
  if (file.peek() == std::ifstream::traits_type::eof())
    throw BitcoinExchange::FileIsEmpty();
  std::string line;
  std::getline(file, line);
  if (type == DATABASEFILE){
    if (line != "date,exchange_rate")
      throw BitcoinExchange::WrongDatabaseHeader();
  }
  else if (type == INPUTFILE) {
    if (line != "date | value")
      throw BitcoinExchange::WrongInputfileHeader();
  }
  return ;
}

bool  BitcoinExchange::get_token_date(std::string const & token_litteral, double *token_value) const{

  char *rest = NULL;
  *token_value = strtod(token_litteral.c_str(), &rest);
  if (!static_cast<std::string>(rest).empty())
    return false;
  return true;
}

bool BitcoinExchange::is_leap_year(double year) const{

  year = static_cast<int>(year);
  for (int leap = 2012; leap <= 2024; leap += 4)
  {
    if (year == leap)
      return true;
  }
  return false;
}

bool  BitcoinExchange::date_is_valid(std::string const & date) const{

  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    return false;
  double year;
  double month;
  double day;
  if (!get_token_date(date.substr(0, 4), &year) || !get_token_date(date.substr(5, 2), &month) || !get_token_date(date.substr(8, 2), &day))
    return false;
  if (year < 2009 || year > 2024)
    return false;
  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;
  if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  if (month == 2 && is_leap_year(year) && day > 29)
    return false;
  if (month == 2 && !is_leap_year(year) && day > 28)
    return false;
  return true;
}

bool  BitcoinExchange::btc_value_is_valid(std::string const & value) const{

  char *rest = NULL;
  long double btc_value = strtold(value.c_str(), &rest); 
  if (!static_cast<std::string>(rest).empty())
    return false;
  if (btc_value <= -(std::numeric_limits<double>::max()) || btc_value >= std::numeric_limits<float>::max())
    return false;
  if (btc_value < 0)
    return false;
  return true;
}

void  BitcoinExchange::parse_data_file(std::ifstream & db_file){

  std::string line;
  std::string date;
  std::string value;
  size_t separator;

  while(std::getline(db_file, line)){

    separator = line.find(',');
    if (separator != 10 || separator == std::string::npos || line.size() < 12){
      db_file.close();
      throw BitcoinExchange::BadInputInDatabase();
    }
    date = line.substr(0, separator);
    value = line.substr(separator + 1);
    if (!date_is_valid(date) || !btc_value_is_valid(value)){
      db_file.close();
      throw BitcoinExchange::BadInputInDatabase();
    }
    _dataset.insert(std::make_pair(date, strtod(value.c_str(), NULL)));
  }
}

void  BitcoinExchange::print_data_set(void)const{

  for (std::map<std::string, double>::const_iterator it = _dataset.begin(); it != _dataset.end(); it++)
    std::cout << it->first << ": " << it->second << std::endl;
  return ;
}

void  BitcoinExchange::set_database(void){

  std::ifstream db_file(DATABASENAME);

  check_input_file(db_file, DATABASEFILE);
  parse_data_file(db_file);
  db_file.close();
}

bool  BitcoinExchange::amount_value_is_valid(std::string const & value, std::string const & line) const{

  char *rest = NULL;
  double input_value = strtod(value.c_str(), &rest);
  if (!static_cast<std::string>(rest).empty())
    return (std::cerr << "Error: bad input => " << line << std::endl, false);
  if (input_value < 0)
    return (std::cerr << "Error: not a positive number." << std::endl, false);
  if (input_value >= std::numeric_limits<int>::max())
    return (std::cerr << "Error: too large a number." << std::endl, false);
  return true; 
}

bool BitcoinExchange::get_previous_date(std::string & date) const{

  int day = atoi(date.substr(8, 2).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int year = atoi(date.substr(0, 4).c_str());

  day--;
  if (!day){
    month--;
    if (!month){
      month = 12;
      year--;
      if (year < 2009)
        return (std::cerr << "Error: cannot find previous date" << std::endl, false); 
      if (month == 2 && is_leap_year(static_cast<double>(year)))
        day = 29;
      else if (month == 4 || month == 6 || month == 9 || month == 11)
        day = 30;
      else 
        day = 31;
    }
  }
  std::ostringstream newDateStream;
  newDateStream << year << "-";
  (month < 10) ? newDateStream << "0" << month << "-" : newDateStream << month << "-";
  (day < 10) ? newDateStream << "0" << day : newDateStream << day;
  date = newDateStream.str();
  return true;
}

bool BitcoinExchange::get_value_from_date(std::string & date, double * btc_value) const {

  while (_dataset.find(date) == _dataset.end()){
    if(!get_previous_date(date))
      return false;
  }
  *btc_value = (*_dataset.find(date)).second;
  return true;
}

size_t  BitcoinExchange::get_precision_from_value(double btc_value) const{

  std::stringstream tmp_stream;

  tmp_stream << btc_value;
  std::string value_to_str = tmp_stream.str();
  return (value_to_str.size() - 1 - value_to_str.find("."));
}

void  BitcoinExchange::parse_input_file(std::ifstream & input_file) const{

  std::string line;
  std::string date;
  std::string amount;
  double btc_value;
  long double result;
  size_t separator;

  while(std::getline(input_file, line)){

    separator = line.find('|');
    if (separator == std::string::npos || line.size() < 10){
      std::cerr << "Error: bad input => " << line << std::endl;
      continue ;
    }
    date = line.substr(0, separator - 1);
    if (!date_is_valid(date)){
      std::cerr << "Error: bad input => " << line << std::endl;
      continue ;
    }
    amount = line.substr(separator + 1);
    if (!amount_value_is_valid(amount, line))
      continue ;
    if (!get_value_from_date(date, &btc_value))
      continue;
    result = strtod(amount.c_str(), NULL) * btc_value;
    if (result < 0 || result >= std::numeric_limits<double>::max()){
      std::cerr << "Error: too large of a number" << line << std::endl;
      continue ;
    }
    std::cout << date << " =>" << amount <<  " = ";
    //std::cout << std::fixed << std::setprecision(get_precision_from_value(btc_value)) << result << std::endl;
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
  }
  return;
}

void  BitcoinExchange::exchange(std::string const file_name) const{

  std::ifstream input_file(file_name.c_str());

  check_input_file(input_file, INPUTFILE);
  parse_input_file(input_file);
  input_file.close();
}


////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  BitcoinExchange::FileNotOpen::what() const throw() {

  return "File could not be opened !";
}

const char *  BitcoinExchange::FileIsEmpty::what() const throw() {

  return "File is Empty !";
}

const char *  BitcoinExchange::WrongDatabaseHeader::what() const throw() {

  return "Header of Database is wrong !";
}

const char *  BitcoinExchange::WrongInputfileHeader::what() const throw() {

  return "Header of input file is wrong !";
}

const char *  BitcoinExchange::BadInputInDatabase::what() const throw() {

  return "Bad input in Database !";
}
