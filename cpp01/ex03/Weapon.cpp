/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:24:54 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 19:32:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){

    return ;
}

Weapon::~Weapon(void){

    return ;
}

std::string const & Weapon::getType(void){

    return this->_type;
}

void    Weapon::setType(std::string type){

    this->_type = type;
    return ;
}
