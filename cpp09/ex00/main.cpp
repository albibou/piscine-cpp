/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:04:04 by atardif           #+#    #+#             */
/*   Updated: 2024/05/31 14:04:06 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

  if (argc != 2)
    return (std::cout << "Use with a file as argument" << std::endl, EXIT_FAILURE);
  try{
    BitcoinExchange btc;
    btc.exchange(argv[1]);
  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }   
  return (0);
}
