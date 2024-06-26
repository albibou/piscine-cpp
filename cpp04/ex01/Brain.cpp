/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:07:20 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:07:21 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
 
Brain::Brain(void){
 
    std::cout << "Default Brain Constructor called" << std::endl;
    return ;
}
 
Brain::Brain(Brain const & src){
 
    *this = src;
    std::cout << "Copy Brain Constructor called" << std::endl;
    return ;
}
 
Brain::~Brain(void){
 
    std::cout << "Default Brain destructor called" << std::endl;
    return ;
}
 
Brain & Brain::operator=(Brain const & rhs){

    for(int i = 0; i < 100; i++)
        this->ideas[i] = rhs.ideas[i];
    std::cout << "Brain assignation operator called" << std::endl;
    return *this;
}


