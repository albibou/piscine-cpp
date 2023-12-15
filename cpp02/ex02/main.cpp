/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:41 by atardif           #+#    #+#             */
/*   Updated: 2023/12/15 11:19:42 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void){

    Fixed   a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed   c (42);
    Fixed   d(10.5f);


    std::cout << "Raw bits a :" << a.getRawBits() << std::endl;
    std::cout << "a value : " << a << std::endl;
    std::cout << "++a : " << ++a << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "a++ : " << a++ << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "--a : " << --a << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "a-- : " << a-- << std::endl;
    std::cout << "a : " << a << std::endl;

    std::cout << "c > d : " << (c > d) << std::endl;
    std::cout << "c < d : " << (c < d) << std::endl;
    std::cout << "c >= d : " << (c >= d) << std::endl;
    std::cout << "c <= d : " << (c <= d) << std::endl;
    std::cout << "c == d : " << (c == d) << std::endl;
    std::cout << "c != d : " << (c != d) << std::endl;

    std::cout << "c + d : " << (c + d) << std::endl;
    std::cout << "c - d : " << (c - d) << std::endl;
    std::cout << "c * d : " << (c * d) << std::endl;
    std::cout << "c / d : " << (c / d) << std::endl;

    std::cout << b << std::endl;

    std::cout << "Max between a = " << a << " and b = " << b << " : " << Fixed::max(a, b) << std::endl;
    std::cout << "Min between a = " << a << " and b = " << b << " : " << Fixed::min(a, b) << std::endl;

    
    return (0);
}

