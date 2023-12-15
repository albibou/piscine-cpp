/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:26 by atardif           #+#    #+#             */
/*   Updated: 2023/12/15 11:19:27 by atardif          ###   ########.fr       */
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

Fixed::Fixed(int const i){

    std::cout << "Int constructor called" << std::endl; 
    _rawBits = i << _fractBits;;
    return ;
}

Fixed::Fixed(float const f){

    std::cout << "Float constructor called" << std::endl; 
    _rawBits = roundf(f * (1 << this->_fractBits));
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

    return this->_rawBits;
}

void    Fixed::setrawBits(int const raw){

    this->_rawBits = raw;
    return ;
}

float   Fixed::toFloat(void) const {

    return (float)(this->_rawBits) / (1 << this->_fractBits);
}

int   Fixed::toInt(void) const {

    return (this->_rawBits >> this->_fractBits);
}

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs){

    o << rhs.toFloat();
    return o;
}
