/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:14:31 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:14:32 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
 
MateriaSource::MateriaSource(void){
 
    std::cout << "Default Constructor called" << std::endl; 
    return ;
}
 
MateriaSource::MateriaSource(MateriaSource const & src){
 
    std::cout << "Copy Constructor called" << std::endl; 
    return ;
}
 
MateriaSource::~MateriaSource(void){
 
    std::cout << "Default Destructor called" << std::endl; 
    return ;
}
 
MateriaSource & MateriaSource::operator=(MateriaSource const & rhs){
 
    //this->default = rhs->default;
    return *this;
}


