/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:38:23 by atardif           #+#    #+#             */
/*   Updated: 2023/11/15 17:12:55 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <sstream>

#define GET_INDEX "Please enter an index (Or EXIT to come back) "
#define BAD_INDEX "Index can only be between 1 and 8"
#define NO_CONTACT "This index is not filled yet "

class   PhoneBook{

private :

    Contact _contacts[8];
    int     _last_index; 

    bool    _check_index(std::string str, int *i) const;
    void    _display_a_contact(void) const;
    void    _display_a_line(int n, std::string s1, std::string s2, std::string s3) const;

public :

    PhoneBook();
    ~PhoneBook();

    void    display_all_contacts(void) const;
    void    get_contact(void);

};

#endif
