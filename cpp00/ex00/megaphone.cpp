/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:05:06 by atardif           #+#    #+#             */
/*   Updated: 2023/11/10 12:39:42 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <ctype.h>
#include <string.h>

void    ft_upper_phrase(char *str)
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
        std::cout << (char)toupper(str[i]);
    return ;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int i = 1; i < argc; i++)
        ft_upper_phrase(argv[i]);
    std::cout << std::endl;
    return (0);
}
