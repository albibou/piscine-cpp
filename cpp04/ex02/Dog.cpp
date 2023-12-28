/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:08:36 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:08:41 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Aanimal("Dog"){
 
    _brain = new Brain;
    for (int i = 0; i < 100; i++)
        _brain->ideas[i] = STD_DOGIDEA; 
    std::cout << "Default Dog Constructor Called" << std::endl;
    return ;
}
 
Dog::Dog(Dog const & src) : Aanimal("Dog"){

    this->type = src.type;
    if (src._brain == NULL)
        this->_brain = NULL;
    else
        this->_brain = new Brain(*src._brain);
    std::cout << "Copy Dog Constructor Called" << std::endl;
    return ;
}
 
Dog::~Dog(void){

    delete _brain;
    std::cout << "Default Dog Destructor Called" << std::endl;
    return ;
}
 
Dog & Dog::operator=(Dog const & rhs){
    
    this->type = rhs.type;
    delete this->_brain;
    if (rhs._brain == NULL)
        this->_brain = NULL;
    else
        this->_brain = new Brain(*rhs._brain);
    std::cout << "Dog assignation operator Called" << std::endl;
    return *this;
}

void    Dog::makeSound(void) const{

    std::cout << "'Woof, woof'" << std::endl;
    return ;
}

void    Dog::fillIdea(std::string idea, int index){

    if (index < 1 || index > 100)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    this->_brain->ideas[index - 1] = idea;
    return ;
}

void    Dog::displayIdeas(void) const{

    for (int i = 0; i < 100; i++)
        this->displayanIdea(i);
    return ;
}

void    Dog::displayanIdea(int index) const{
    
    if (index < 0 || index > 99)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    std::cout << "Idea n " << index + 1 << " " << this->_brain->ideas[index] << std::endl; 
    return;
}
