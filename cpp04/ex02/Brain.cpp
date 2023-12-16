/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:09:47 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:09:49 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
 
Brain::Brain(void){
 
    //std::cout << "Default Brain contructor called" << std::endl;
    return ;
}
 
Brain::Brain(Brain const & src){
 
    *this = src;
    std::cout << "Copy Brain contructor called" << std::endl;
    return ;
}
 
Brain::~Brain(void){
 
    //std::cout << "Default Brain destructor called" << std::endl;
   return ;
}
 
Brain & Brain::operator=(Brain const & rhs){

    for(int i = 0; i < 100; i++)
        this->ideas[i] = rhs.ideas[i];
   return *this;
}


