/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:41:43 by atardif           #+#    #+#             */
/*   Updated: 2023/11/10 17:21:03 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <ctype.h>
#include <cstdlib>

class   Contact{

private :

    std::string _FirstName;
    std::string _LastName;
    std::string _NickName;
    std::string _PhoneNumber;
    std::string _DarkSecret;

    std::string    _get_litteral(std::string str);
    std::string    _get_number(std::string str);
    bool           _check_number(std::string str);

public :

    Contact();
    ~Contact();
    
    void    fill_contact(void);
};

#endif
