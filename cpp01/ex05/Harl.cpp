/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:26:49 by atardif           #+#    #+#             */
/*   Updated: 2023/12/12 14:27:05 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
 
Harl::Harl()
{
    return ;
}
 
 
Harl::~Harl()
{
    return ; 
}

void    Harl::debug(void) {

    std::cout << DEBUG << std::endl;
    return ;
}

void    Harl::info(void) {

    std::cout << INFO << std::endl;
    return ;
}

void    Harl::warning(void) {

    std::cout << WARNING << std::endl;
    return ;
}


void    Harl::error(void) {

    std::cout << ERROR << std::endl;
    return ;
}

void    Harl::complain(std::string level){
    
    void    (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string  levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for(int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return (this->*functions[i])();
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return ;
}
