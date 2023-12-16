/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:44 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:05:46 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
 
    std::cout << "Default Dog Constructor Called" << std::endl;
    return ;
}
 
Dog::Dog(Dog const & src){
 
    *this = src;
    std::cout << "Copy Dog Constructor Called" << std::endl;
    return ;
}
 
Dog::~Dog(void){
 
    std::cout << "Default Dog Destructor Called" << std::endl;
    return ;
}
 
Dog & Dog::operator=(Dog const & rhs){
 
   this->type = rhs.type;
   return *this;
}

void    Dog::makeSound(void) const{

    std::cout << "'Woof, woof'" << std::endl;
    return ;
}
