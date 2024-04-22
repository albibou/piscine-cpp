/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:44:23 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:44:24 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void){

  Data  *data_ptr = new Data;
  Data  *deserialized;

  data_ptr->num = 1000;
  data_ptr->str = "Hello";

  std::cout << "Data_ptr adress : " << data_ptr << std::endl;
  std::cout << "Data->num : " << data_ptr->num << std::endl;
  std::cout << "Data->str : " << data_ptr->str << std::endl;

  deserialized = Serializer::deserialize(Serializer::serialize(data_ptr));

  std::cout << "Deserialized adress : " << deserialized << std::endl;
  std::cout << "Deserialized->num : " << deserialized->num << std::endl;
  std::cout << "Deserialized->str : " << deserialized->str << std::endl;

  return (0);
}
