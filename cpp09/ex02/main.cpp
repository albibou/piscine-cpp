/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:35:11 by atardif           #+#    #+#             */
/*   Updated: 2024/05/31 11:35:13 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){

  if (argc < 2){
    std::cout << "Error: Use with at list two positive integers as arguments." << std::endl;
    return (1);
  }
  try {
    PmergeMe<std::vector> vec_to_sort;
    PmergeMe<std::deque> deque_to_sort;
    vec_to_sort.sort_container(argv + 1, PRINT_CONTAINER);
    deque_to_sort.sort_container(argv + 1, NO_PRINT_CONTAINER);
    vec_to_sort.print_time_to_sort("vector");
    deque_to_sort.print_time_to_sort("deque");

  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
