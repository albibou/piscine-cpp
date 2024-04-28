/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:45:58 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:45:59 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

static std::string generate_random_string(void){
  const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  std::string result;

  for (unsigned int i = 0; i < 8; i++)
    result += alphabet[rand() % (sizeof(alphabet) - 1)];
  return result;
}

static void string_array_tests(void){
  std::cout << std::endl << "Tests on string Array" << std::endl;
  Array<std::string>  array1(5);
  Array<std::string>  array2;

  std::cout << "Let's fill the Array1 with values and print it" << std::endl;

  for(unsigned int i = 0; i < array1.size(); i++){

    try{
      array1[i] = generate_random_string();

      std::cout << "Array1[" << i << "] = " << array1[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << std::endl << "We'll now print the Array2 which is empty. Use assignation operator to assign it Array1 values, then print Array2 again" << std::endl;

  unsigned int i;
  for (i = 0; i < array2.size(); i++){
    try {
      std::cout << "Array2[" << i <<"] = " << array2[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }

  array2 = array1;
  for (unsigned int i = 0; i < array2.size(); i++){
      try {
        std::cout << "Array2[" << i <<"] = " << array2[i] << std::endl;
      }
      catch (const std::exception & e){
        std::cerr << e.what() << std::endl;
      }
    }

  std::cout << std::endl << "To prove deep copy/assignation we're going to change Array2. If Array remains the same after, the copy is deep " << std::endl;
  for(unsigned int i = 0; i < array2.size(); i++){

    try{
      array2[i] = generate_random_string();

      std::cout << "Array2[" << i << "] = " << array2[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  for(unsigned int i = 0; i < array1.size(); i++){

    try{
      std::cout << "Array1[" << i << "] = " << array1[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << std::endl << "We're going to try to access an invalid index in the Array " << std::endl;
  try {
    std::cout << array1[1000] << std::endl;
  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return ;


  return ;
}

static void int_array_tests(void){

  std::cout << "Tests on int Array" << std::endl;
  Array<int>  array1(5);
  Array<int>  array2;

  std::cout << "Let's fill the Array1 with values and print it" << std::endl;

  for(unsigned int i = 0; i < array1.size(); i++){

    try{
      array1[i] = rand() % 100 + 1;

      std::cout << "Array1[" << i << "] = " << array1[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << std::endl << "We'll now print the Array2 which is empty. Use assignation operator to assign it Array1 values, then print Array2 again" << std::endl;

  unsigned int i;
  for (i = 0; i < array2.size(); i++){
    try {
      std::cout << "Array2[" << i <<"] = " << array2[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }

  array2 = array1;
  for (unsigned int i = 0; i < array2.size(); i++){
      try {
        std::cout << "Array2[" << i <<"] = " << array2[i] << std::endl;
      }
      catch (const std::exception & e){
        std::cerr << e.what() << std::endl;
      }
    }

  std::cout << std::endl << "To prove deep copy/assignation we're going to change Array2. If Array remains the same after, the copy is deep " << std::endl;
  for(unsigned int i = 0; i < array2.size(); i++){

    try{
      array2[i] = rand() % 100 + 1;

      std::cout << "Array2[" << i << "] = " << array2[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  for(unsigned int i = 0; i < array1.size(); i++){

    try{
      std::cout << "Array1[" << i << "] = " << array1[i] << std::endl;
    }
    catch (const std::exception & e){
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << std::endl << "We're going to try to access an invalid index in the Array " << std::endl;
  try {
    std::cout << array1[1000] << std::endl;
  }
  catch (const std::exception & e){
    std::cerr << e.what() << std::endl;
  }
  return ;
}

int main(void){

  int_array_tests();
  string_array_tests();
  return 0;
}
