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
    if (line != "date | Value")
      throw BitcoinExchange::WrongInputfileHeader();
  }
  return ;
}

bool  BitcoinExchange::date_is_valid(std::string const & date) const{

  return true;
}

bool  BitcoinExchange::btc_value_is_valid(std::string const & value) const{

  return true;
}

void  BitcoinExchange::parse_input_file(std::ifstream & db_file){

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
    value = line.substr(separator++);
    if (!date_is_valid(date) || !btc_value_is_valid(value)){
      db_file.close();
      throw BitcoinExchange::BadInputInDatabase();
    }
    _dataset.insert(std::make_pair(date, strtod(value.c_str(), NULL)));
  }
  db_file.close();
}

void  BitcoinExchange::set_database(void){

  std::ifstream db_file(DATABASENAME);

  check_input_file(db_file, DATABASEFILE);
  parse_input_file(db_file);
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
