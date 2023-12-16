/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:56 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:57 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
 
ICharacter::ICharacter(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
ICharacter::ICharacter(ICharacter const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
ICharacter::~ICharacter(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
ICharacter & ICharacter::operator=(ICharacter const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


