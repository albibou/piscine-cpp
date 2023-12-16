/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:14:09 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:14:10 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
 
IMateriaSource::IMateriaSource(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
IMateriaSource::IMateriaSource(IMateriaSource const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
IMateriaSource::~IMateriaSource(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
IMateriaSource & IMateriaSource::operator=(IMateriaSource const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


