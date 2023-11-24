/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:05:46 by atardif           #+#    #+#             */
/*   Updated: 2023/11/24 11:19:16 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Phonebook.hpp"

PhoneBook::PhoneBook(void) : _last_index(-1) {
    return ;
}

PhoneBook::~PhoneBook(void){
    return ;
}

bool    PhoneBook::_check_index(std::string str, int *i) const {

    *i = 0;
    if (str.length() != 1 || str[*i] == '0' || !isdigit(str[*i]))
        return  (std::cout << BAD_INDEX << std::endl, false);
    *i = str[*i] - '0';
    if (*i < 1 || *i > 8)
        return  (std::cout << BAD_INDEX << std::endl, false);
    else if (this->_last_index <= 7 && *i > this->_last_index + 1)
        return  (std::cout << NO_CONTACT << std::endl, false);
    return (true);
}

void    PhoneBook::_display_a_contact(void) const {

    std::string buffer;
    int i = 0;
    Contact contact;

    while (1)
    {
        std::cout << GET_INDEX <<std::endl;
        if(!std::getline(std::cin, buffer))
        {
            std::cout << std::endl << EXIT_PROGRAM << std::endl;
            exit(1);
        }
        if (!buffer.length())
            std::cout << EMPTY_FIELD << std::endl;
        else if (buffer == "EXIT")
            return ;
        else if (!_check_index(buffer, &i))
            continue ;
        else
            break ;
    }
    contact = this->_contacts[i - 1];
    std::cout << "First Name : " << contact.get_content("First") << std::endl; 
    std::cout << "Last Name : " << contact.get_content("Last") << std::endl; 
    std::cout << "Nickname : " << contact.get_content("Nick") << std::endl; 
    std::cout << "Phone Number : " << contact.get_content("Phone") << std::endl; 
    std::cout << "Darkest Secret : " << contact.get_content("Dark") << std::endl; 
    return ;
}

void    PhoneBook::_display_a_line(int n, std::string s1, std::string s2, std::string s3) const   {

    std::string tab[3]={s1, s2, s3};

    std::cout << "|";
    if (n == -1)
        std::cout << std::right << std::setw(10) << "Index";
    else
        std::cout << std::right << std::setw(10) << n + 1;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "|";
        if (tab[i].size() > 10)
            std::cout << std::right << std::setw(10) << tab[i].substr(0,9) + ".";
        else
            std::cout << std::right << std::setw(10) << tab[i];
    }
    std::cout << "|" <<  std::endl;
    return ;
}

void    PhoneBook::display_all_contacts(void) const {

    _display_a_line(-1 , "First Name", "Last Name", "Nickname");
    for (int i = 0; i < 8 ; i++)
    {
        Contact contact = this->_contacts[i];
        _display_a_line(i , contact.get_content("First"), contact.get_content("Last"), contact.get_content("Nick"));
    }
    _display_a_contact();
    return ;
}

void    PhoneBook::get_contact(void)
{
    static int  i = 0;

    this->_last_index++;
    this->_contacts[i % 8].fill_contact();
    i++;
    if (i == 8)
        i = 0;
    return ;
}
