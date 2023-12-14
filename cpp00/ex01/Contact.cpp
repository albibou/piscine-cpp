/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:05:58 by atardif           #+#    #+#             */
/*   Updated: 2023/12/10 16:22:46 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"

Contact::Contact(void){
    return ;
}

Contact::~Contact(void){
    return ;
}

bool        Contact::_check_format(std::string str) const{

    bool    achar = false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isgraph((int)str[i]))
            achar = true;
        if (!isprint((int)str[i]))
            return (false);
    }
    if (!achar)
        return (false);
    return (true);
}

std::string    Contact::_fill_litteral(std::string str) const{
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
        else if (!this->_check_format(buffer))
            std::cout << CHAR_ERROR << std::endl;
        else
            break ;
    }
    return (buffer);
}

bool           Contact::_check_number(std::string str) const {
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (!isdigit((int)str[i]))
            return (false);
    }
    return (true);
}

std::string    Contact::_fill_number(std::string str) const {
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

std::string     Contact::get_content(std::string str) const{

    if (str == "First")
        return this->_FirstName;
    else if (str == "Last")
        return this->_LastName;
    else if (str == "Nick")
        return this->_NickName;
    else if (str == "Phone")
        return this->_PhoneNumber;
    else
        return this->_DarkSecret;
}

void    Contact::fill_contact() {
    this->_FirstName = this->_fill_litteral("First Name : ");
    this->_LastName = this->_fill_litteral("Last Name : ");
    this->_NickName = this->_fill_litteral("Nick Name : ");
    this->_PhoneNumber = this->_fill_number("Phone Number : ");
    this->_DarkSecret = this->_fill_litteral("Dark Secret : ");
    return ;
}
