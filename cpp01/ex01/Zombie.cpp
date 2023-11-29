/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:06:25 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 17:45:17 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Default") {

    return;
} 

Zombie::~Zombie(void){

    std::cout << this->_name << " has been destroyed" << std::endl;
    return;
}

void    Zombie::announce(void){

    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void    Zombie::set_name(std::string name){

    this->_name = name;
    return ;
}
