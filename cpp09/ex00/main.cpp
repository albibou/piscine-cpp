#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

  if (argc != 2)
    return (std::cout << "Use with a file as argument" << std::endl, EXIT_FAILURE);
  BitcoinExchange btc;
  try{
    btc.exchange(argv[1]);
  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
