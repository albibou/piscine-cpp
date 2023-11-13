/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:05:46 by atardif           #+#    #+#             */
/*   Updated: 2023/11/10 19:07:26 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Phonebook.hpp"

PhoneBook::PhoneBook(void) : _last_index(-1) {
    return ;
}

PhoneBook::~PhoneBook(void){
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
