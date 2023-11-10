/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:06:10 by atardif           #+#    #+#             */
/*   Updated: 2023/11/10 18:42:00 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Phonebook.hpp"
#include <iostream>
#include <cstdio>

#define BAD_INPUT "You can only use ADD / SEARCH / EXIT"


int main(void)
{
    PhoneBook   phonebook;
    std::string prompt;
    std::string tmp;

    while(1)
    {
        if(!std::getline(std::cin, prompt))
            break ;
        if (prompt.compare("ADD"))
            std::cout << prompt << std::endl;
        else if (prompt.compare("SEARCH"))
            std::cout << prompt << std::endl;
        else if (prompt.compare("EXIT"))
            break ;
        else
            std::cout << BAD_INPUT << std::endl;
    }
    return (0);
}
