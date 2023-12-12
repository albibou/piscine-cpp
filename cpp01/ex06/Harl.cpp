/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:27:29 by atardif           #+#    #+#             */
/*   Updated: 2023/12/12 14:27:30 by atardif          ###   ########.fr       */
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

    std::cout << "[DEBUG]" << std::endl;
    std::cout << DEBUG << std::endl << std::endl;
    return ;
}

void    Harl::info(void) {

    std::cout << "[INFO]" << std::endl;
    std::cout << INFO << std::endl << std::endl;
    return ;
}

void    Harl::warning(void) {

    std::cout << "[WARNING]" << std::endl;
    std::cout << WARNING << std::endl << std::endl;
    return ;
}


void    Harl::error(void) {

    std::cout << "[ERROR]" << std::endl;
    std::cout << ERROR << std::endl << std::endl;
    return ;
}

void    Harl::complain(std::string level){
    
    void    (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string  levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4)
    {
        if (levels[i] == level)
            break;
        i++;
    }
    switch (i)
        {
            case 0 :
                (this->*functions[0])();
            case 1 :
                (this->*functions[1])();
            case 2 :
                (this->*functions[2])();
            case 3 :
                (this->*functions[3])();
                break ;
            default :
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    return ;
}
