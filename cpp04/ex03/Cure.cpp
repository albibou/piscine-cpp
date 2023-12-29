/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:36 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:37 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
 
Cure::Cure(void) : AMateria("cure"){
 
    std::cout << "Default Cure Constructor called" << std::endl; 
    return ;
}
 
Cure::Cure(Cure const & src) : AMateria(src){
 
    std::cout << "Copy Cure Constructor called" << std::endl; 
    return ;
}
 
Cure::~Cure(void){
 
    std::cout << "Default Cure Destructor called" << std::endl; 
    return ;
}
 
Cure & Cure::operator=(Cure const & rhs){

    (void)rhs;
    std::cout << "Cure objects are always of the same type so assignation is useless" << std::endl;
    return *this;
}

AMateria*    Cure::clone(void) const{

    AMateria *clone = new Cure();
    return clone;
}

void    Cure::use(ICharacter& target){

    std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
    return ;
}
