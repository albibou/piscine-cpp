/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:49 by atardif           #+#    #+#             */
/*   Updated: 2023/12/15 11:19:50 by atardif          ###   ########.fr       */
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
    _rawBits = roundf(f * (1 << _fractBits));
    return ;
}


Fixed::~Fixed(void){
 
    std::cout << "Destructor called" << std::endl;
    return ;
}

bool    Fixed::operator>(Fixed const & rhs) const{

    return this->_rawBits > rhs._rawBits;
}

bool    Fixed::operator<(Fixed const & rhs) const{

    return this->_rawBits < rhs._rawBits;
}

bool    Fixed::operator>=(Fixed const & rhs) const{

    return this->_rawBits >= rhs._rawBits;
}

bool    Fixed::operator<=(Fixed const & rhs) const{

    return this->_rawBits <= rhs._rawBits;
}

bool    Fixed::operator==(Fixed const & rhs) const{

    return this->_rawBits == rhs._rawBits;
}

bool    Fixed::operator!=(Fixed const & rhs) const{

    return this->_rawBits != rhs._rawBits;
}

Fixed   Fixed::operator+(Fixed const & rhs) const{

    return Fixed(this->toFloat() + rhs.toFloat());    
}

Fixed   Fixed::operator-(Fixed const & rhs) const{

    return Fixed(this->toFloat() - rhs.toFloat());    
}

Fixed   Fixed::operator*(Fixed const & rhs) const{

    return Fixed(this->toFloat() * rhs.toFloat());    
}

Fixed   Fixed::operator/(Fixed const & rhs) const{

    return Fixed(this->toFloat() / rhs.toFloat());    
}

Fixed   Fixed::operator++(void){

    Fixed   tmp;
    tmp._rawBits = ++_rawBits;
    return tmp;
}

Fixed   Fixed::operator--(void){

    Fixed   tmp;
    tmp._rawBits = --_rawBits;
    return tmp;
}

Fixed   Fixed::operator++(int){

    Fixed   tmp;
    tmp._rawBits = _rawBits++;
    return tmp;
}

Fixed   Fixed::operator--(int){

    Fixed   tmp;
    tmp._rawBits = _rawBits--;
    return tmp;
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

Fixed &  Fixed::min(Fixed & lhs, Fixed & rhs){

    if (lhs < rhs)
        return lhs;
    return rhs;
}

Fixed const &  Fixed::min(Fixed const & lhs, Fixed const & rhs){

    if (lhs < rhs)
        return lhs;
    return rhs;
}

Fixed &  Fixed::max(Fixed & lhs, Fixed & rhs){

    if (lhs > rhs)
        return lhs;
    return rhs;
}

Fixed const &  Fixed::max(Fixed const  & lhs, Fixed const & rhs){

    if (lhs > rhs)
        return lhs;
    return rhs;
}


std::ostream &  operator<<(std::ostream & o, Fixed const & rhs){

    o << rhs.toFloat();
    return o;
}
