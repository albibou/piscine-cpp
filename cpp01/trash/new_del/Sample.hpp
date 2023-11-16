/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:09 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 14:32:11 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_H
# define SAMPLE_H

# include <string>
# include <iostream>

# define default_login "jcvd"

class   Sample{

    private :

        std::string _login;

    public :

        Sample(std::string login);
        ~Sample(void);

};

class   Sample2{

    private :

        std::string _login;

    public :

        Sample2(void);
        ~Sample2(void);

};


#endif
