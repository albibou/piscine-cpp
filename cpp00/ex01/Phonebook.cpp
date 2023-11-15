/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:05:46 by atardif           #+#    #+#             */
/*   Updated: 2023/11/15 17:13:17 by atardif          ###   ########.fr       */
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
    std::stringstream tmp;

    *i = 0;
    if (str.length() != 1)
        std::cout << BAD_INDEX << std::endl;
    *i = str[i] - '0';
    if ((this->last_index <= 7 && )


}

void    PhoneBook::display_a_contact(void) const {

    std::string buffer;
    int *i;

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
        else if (!_check_index(buffer))
            continue ;
        else
            break ;
    }

}

void    PhoneBook::display_a_line(int n, std::string s1, std::string s2, std::string s3) const   {

    std::string tab[3]={s1, s2, s3};

    if (n == -1)
        std::cout << std::right << std::setw(10) << "Index" << "|";
    else
        std::cout << std::right << std::setw(10) << n + 1 << "|";
    for (int i = 0; i < 3; i++)
    {
        if (tab[i].size() >= 10)
            std::cout << std::right << std::setw(10) << tab[i].substr(0,8) << "." << "|";
        else
            std::cout << std::right << std::setw(10) << tab[i] << "|";
    }
    std::cout << std::endl;
    return ;
}

void    PhoneBook::display_all_contacts(void) const {

    display_a_line(-1 , "First Name", "Last Name", "Nickname");
    for (int i = 0; i < 8 ; i++)
    {
        Contact contact = this->_contacts[i];
        display_a_line(i , contact.get_content("First"), contact.get_content("Last"), contact.get_content("Nick"));
    }
    while (1)
    {

    }
    this->display_a_contact();
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
