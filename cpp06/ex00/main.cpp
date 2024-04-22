/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:43:42 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:43:44 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){

  if (argc != 2){
    std::cout << "Use with one litteral argument" << std::endl;
    return (1);
  }
  ScalarConverter::convert(argv[1]);
  return (0);
}
  
