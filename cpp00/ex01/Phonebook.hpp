/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:38:23 by atardif           #+#    #+#             */
/*   Updated: 2023/11/10 16:41:32 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class   PhoneBook{

public :

    Contact contacts[8];

    PhoneBook();
    ~PhoneBook();

    void    display_all_contacts(Contact contacts);
    void    diplay_a_contact(Contact contacts);
    void    fill_a_contact(void);

};

#endif
