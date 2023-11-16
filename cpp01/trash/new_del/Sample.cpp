/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:22:09 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 14:34:15 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample(std::string login) : _login(login) {

    std::cout << "Student : " << this->_login << "Created" << std::endl;
    return ;
}

Sample::~Sample(void){

    std::cout << "Student : " << this->_login << "Deleted" << std::endl;
    return ;
}

Sample2::Sample2(void) : _login(default_login){

    std::cout << "Student : " << this->_login << "Created" << std::endl;
    return ;
}

Sample2::~Sample2(void){

    std::cout << "Student : " << this->_login << "Deleted" << std::endl;
    return ;
}
