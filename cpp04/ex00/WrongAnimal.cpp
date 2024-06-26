/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:06:08 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:06:13 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Default"){
 
    std::cout << "Default WrongAnimal Constructor Called" << std::endl;
    return ;
}
 
WrongAnimal::WrongAnimal(std::string name) : _type(name){
 
    std::cout << "Type WrongAnimal Constructor Called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
 
    *this = src;
    std::cout << "Copy WrongAnimal Constructor Called" << std::endl;
    return ;
}
 
WrongAnimal::~WrongAnimal(void){
 
    std::cout << "Default WrongAnimal Destructor Called" << std::endl;
    return ;
}
 
WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs){
 
   this->_type = rhs._type;
   return *this;
}

void    WrongAnimal::makeSound(void) const{

    std::cout << "'WrongAnimal noiiiise'" << std::endl;
    return ;
}

std::string WrongAnimal::getType(void) const{

    return this->_type;
}
