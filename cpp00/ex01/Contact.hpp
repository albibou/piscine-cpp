/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:41:43 by atardif           #+#    #+#             */
/*   Updated: 2023/11/15 15:07:39 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>

#define EMPTY_FIELD "A field cannot be empty, enter a value" 
#define NOT_NUMBER "A Phone Number can only be composed of digits, please try again"
#define EXIT_PROGRAM    "End of program, exiting ..."

class   Contact{

private :

    std::string _FirstName;
    std::string _LastName;
    std::string _NickName;
    std::string _PhoneNumber;
    std::string _DarkSecret;

    std::string    _fill_litteral(std::string str) const;
    std::string    _fill_number(std::string str) const;
    bool           _check_number(std::string str) const;

public :

    Contact();
    ~Contact();
    
    void            fill_contact(void);
    std::string     get_content(std::string str) const;
};

#endif
