/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:18:54 by atardif           #+#    #+#             */
/*   Updated: 2023/12/15 11:18:56 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
 
Fixed::Fixed(void) : _rawBits(0){
 
    std::cout << "Default constructor called" << std::endl;
    return ;
}
 
Fixed::Fixed(Fixed const & src){
 
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = src.getRawBits();
    return ;
}
 
Fixed::~Fixed(void){
 
    std::cout << "Destructor called" << std::endl;
    return ;
}
 
Fixed &  Fixed::operator=(Fixed const & rhs){
 
    std::cout << "Copy assignement operator called" << std::endl;
    this->_rawBits = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const{

    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void    Fixed::setrawBits(int const raw){

    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
    return ;
}
