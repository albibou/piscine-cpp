/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:49:10 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 14:53:47 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void    byPtr(std::string *str)
{
    *str += "... Tardif Albam";
    return ;
}

void    byconstPtr(std::string const *str)
{
    std::cout << *str << std::endl;
    return ;
}

void    byRef(std::string &str)
{
    str += "... Malou Eddy";
    return ;
}

void    byconstRef(std::string const &str)
{
    std::cout << str << std::endl;
    return ;
}

int main(void){

    std::string str;

    str = "Hello my name is Albam";

    byPtr(&str);
    byconstPtr(&str);

    str = "Hello my name is Eddy";

    byRef(str);
    byconstRef(str);
    return (0);
}
