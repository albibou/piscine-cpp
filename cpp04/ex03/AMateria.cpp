/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:12:36 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:12:37 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
 
AMateria::AMateria(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
AMateria::AMateria(AMateria const & src){
 
    *this = src;
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
AMateria::~AMateria(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
AMateria & AMateria::operator=(AMateria const & rhs){
 
    this->type = rhs.type;
    return *this;
}

std::string const & AMateria::getType(void) const {

    return this->type;
}

AMateria *  AMateria::clone(void) const {

    AMateria    *clone = new AMateria();
    *clone = *this;
    return clone;
}

void    AMateria::use(ICharacter& target){

    // See it later
    return ;
}
