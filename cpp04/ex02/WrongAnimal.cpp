/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:11:57 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:11:57 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Default"){
 
    std::cout << "Default WrongAnimal Constructor Called" << std::endl;
    return ;
}
 
WrongAnimal::WrongAnimal(std::string name) : type(name){
 
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
 
   this->type = rhs.type;
   return *this;
}

void    WrongAnimal::makeSound(void) const{

    std::cout << "'WrongAnimal noiiiise'" << std::endl;
    return ;
}

std::string WrongAnimal::getType(void) const{

    return this->type;
}
