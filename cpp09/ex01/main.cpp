/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:04:17 by atardif           #+#    #+#             */
/*   Updated: 2024/05/31 14:04:19 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){

  if (argc != 2)
    return (std::cout << "Error :" << USAGE << std::endl << EXAMPLE << std::endl, 1);
  RPN rpn;
  if (!rpn.calculate_RPN(argv[1]))
    return (std::cout << "Error :" << rpn.get_error() << std::endl, 1);
  return (0);
}
