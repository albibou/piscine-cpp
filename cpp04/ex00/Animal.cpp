/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:15 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:05:16 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
 
Animal::Animal(void) : type("Default"){
 
    std::cout << "Default Animal Constructor Called" << std::endl;
    return ;
}
 
Animal::Animal(std::string name) : type(name){
 
    std::cout << "Type Animal Constructor Called" << std::endl;
    return ;
}

Animal::Animal(Animal const & src){
 
    *this = src;
    std::cout << "Copy Animal Constructor Called" << std::endl;
    return ;
}
 
Animal::~Animal(void){
 
    std::cout << "Default Animal Destructor Called" << std::endl;
    return ;
}
 
Animal & Animal::operator=(Animal const & rhs){
 
   this->type = rhs.type;
   std::cout << "Animal assignation operator called" << std::endl;
   return *this;
}

std::string Animal::getType(void) const{

    return this->type;
}

void    Animal::makeSound(void) const{

    std::cout << "'Animal noiiiise'" << std::endl;
    return ;
}

