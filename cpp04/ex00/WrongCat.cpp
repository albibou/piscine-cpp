/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:06:42 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:06:43 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
 
WrongCat::WrongCat(void) : WrongAnimal("WrongCat"){
 
    std::cout << "Default WrongCat Constructor Called" << std::endl;
    return ;
}
 
WrongCat::WrongCat(WrongCat const & src){
 
    *this = src;
    std::cout << "Copy WrongCat Constructor Called" << std::endl;
    return ;
}
 
WrongCat::~WrongCat(void){
 
    std::cout << "Default WrongCat Destructor Called" << std::endl;
    return ;
}
 
WrongCat & WrongCat::operator=(WrongCat const & rhs){
 
   this->type = rhs.type;
   return *this;
}

void    WrongCat::makeSound(void) const{

    std::cout << "'Wrong Miaou Miaou' (That's the wrong noise)" << std::endl;
    return ;
}

