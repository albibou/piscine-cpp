/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:34 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:05:35 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
 
Cat::Cat(void) : Animal("Cat"){
 
    std::cout << "Default Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::Cat(Cat const & src){
 
    *this = src;
    std::cout << "Copy Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::~Cat(void){
 
    std::cout << "Default Cat Destructor Called" << std::endl;
    return ;
}
 
Cat & Cat::operator=(Cat const & rhs){

   this->type = rhs.type;
   std::cout << "Cat assignation operator called" << std::endl;
   return *this;
}

void    Cat::makeSound(void) const{

    std::cout << "'Meow'" << std::endl;
    return ;
}
