/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:06:25 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 17:26:44 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str) : _name(str) {

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
