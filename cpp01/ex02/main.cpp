/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:47:35 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 17:57:24 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void){

    std::string str = "HI THIS IS BRAIN";
    std::string*    stringPTR = &str;
    std::string&    stringREF = str;

    std::cout << "Address of str : " << &str << std::endl;
    std::cout << "Address contained in stringPTR : " << stringPTR << std::endl;
    std::cout << "Address held by string REF :  " << &stringREF << std::endl;
    
    std::cout << std::endl;

    std::cout << "Value of str : " << str << std::endl;
    std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;

    return (0);
}
