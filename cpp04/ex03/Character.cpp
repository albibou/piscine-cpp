/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:26 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:27 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
 
Character::Character(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
Character::Character(Character const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
Character::~Character(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
Character & Character::operator=(Character const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


