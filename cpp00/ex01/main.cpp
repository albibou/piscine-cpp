/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:06:10 by atardif           #+#    #+#             */
/*   Updated: 2023/11/15 16:20:31 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Phonebook.hpp"
#include <cstdio>

#define GET_INPUT "Enter one of the following commands : ADD / SEARCH / EXIT"   
#define BAD_INPUT "You can only use ADD / SEARCH / EXIT"

int main(void)
{
    PhoneBook   phonebook;
    std::string prompt;
    std::string tmp;

    while(1)
    {
        std::cout << GET_INPUT << std::endl;
        if(!std::getline(std::cin, prompt))
            break ;
        if (prompt == "ADD")
            phonebook.get_contact();
        else if (prompt == "SEARCH")
            phonebook.display_all_contacts();
        else if (prompt == "EXIT")
            break ;
        else
            continue;
    }
    std::cout << EXIT_PROGRAM << std::endl;
    return (0);
}
