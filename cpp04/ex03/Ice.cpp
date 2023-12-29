/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:45 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:46 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
 
Ice::Ice(void) : AMateria("ice"){
 
    std::cout << "Default Ice Constructor called" << std::endl; 
    return ;
}
 
Ice::Ice(Ice const & src) : AMateria(src){
 
    std::cout << "Copy Ice Constructor called" << std::endl; 
    return ;
}
 
Ice::~Ice(void){
 
    std::cout << "Default Ice Destructor called" << std::endl; 
    return ;
}
 
Ice & Ice::operator=(Ice const & rhs){

    (void)rhs;
    std::cout << "Ice objects are always of the same type so assignation is useless" << std::endl;
    return *this;
}

AMateria*    Ice::clone(void) const{

    AMateria *clone = new Ice();
    return clone;
}

void    Ice::use(ICharacter& target){

    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}
