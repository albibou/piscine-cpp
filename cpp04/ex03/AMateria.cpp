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
 
AMateria::AMateria(void) : _type("Default"){
 
    std::cout << "Default AMateria Constructor called" << std::endl; 
    return ;
}
 
AMateria::AMateria(std::string const & type) : _type(type){

    std::cout << "Parametric AMateria Constructor called" << std::endl;
    return ;
}

AMateria::AMateria(AMateria const & src) : _type(src.getType()){
 
    std::cout << "Copy AMateria Constructor called" << std::endl; 
    return ;
}
 
AMateria::~AMateria(void){
 
    std::cout << "Default AMateria Destructor called" << std::endl; 
    return ;
}
 
AMateria & AMateria::operator=(AMateria const & rhs){

    (void)rhs;
    std::cout << "AMateria objects are always of the same type so assignation is useless" << std::endl;
    return *this;
}

std::string const & AMateria::getType(void) const {

    return this->_type;
}

void    AMateria::use(ICharacter& target){

    (void)target;
    std::cout << "There's no interest in using an AMateria" << std::endl;
    return ;
}
