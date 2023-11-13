/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:05:58 by atardif           #+#    #+#             */
/*   Updated: 2023/11/10 19:07:28 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"

#define EMPTY_FIELD "A field cannot be empty, enter a value" 
#define NOT_NUMBER "A Phone Number can only be composed of digits, please try again"
#define EXIT_PROGRAM    "End of program, exiting ..."

Contact::Contact(void){
    return ;
}

Contact::~Contact(void){
    return ;
}

std::string    Contact::_get_litteral(std::string str)
{
    std::string buffer;

    while (1)
    {
        std::cout << str;
        if(!std::getline(std::cin, buffer))
        {
            std::cout << std::endl << EXIT_PROGRAM << std::endl;
            exit(1);
        }
        if (!buffer.length())
            std::cout << EMPTY_FIELD << std::endl;
        else
            break ;
    }
    return (buffer);
}

bool           Contact::_check_number(std::string str)
{
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (!isdigit((int)str[i]))
            return (false);
    }
    return (true);
}

std::string    Contact::_get_number(std::string str)
{
    std::string buffer;

    while (1)
    {
        std::cout << str;
        if(!std::getline(std::cin, buffer))
        {
            std::cout << std::endl << EXIT_PROGRAM << std::endl;
            exit(1);
        }
        if (!buffer.length())
            std::cout << EMPTY_FIELD << std::endl;
        else if (!_check_number(buffer))
            std::cout << NOT_NUMBER << std::endl;
        else
            break ;
    }
    return (buffer);
}

void    Contact::fill_contact() {
    this->_FirstName = this->_get_litteral("First Name : ");
    this->_LastName = this->_get_litteral("Last Name : ");
    this->_NickName = this->_get_litteral("Nick Name : ");
    this->_PhoneNumber = this->_get_number("Phone Number : ");
    this->_DarkSecret = this->_get_litteral("Dark Secret : ");
    return ;
}
