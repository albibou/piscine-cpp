/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:08:26 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:08:27 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
 
Cat::Cat(void) : Animal("Cat"){

    _brain = new Brain();
    for (int i = 0; i < 100; i++)
        _brain->ideas[i] = STD_CATIDEA;
    std::cout << "Default Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::Cat(Cat const & src) : Animal("Cat"){

    this->type = src.type;
    if (src._brain == NULL)
        this->_brain = NULL;
    else
        this->_brain = new Brain(*src._brain);
    std::cout << "Copy Cat Constructor Called" << std::endl;
    return ;
}
 
Cat::~Cat(void){

    delete _brain;
    std::cout << "Default Cat Destructor Called" << std::endl;
    return ;
}
 
Cat & Cat::operator=(Cat const & rhs){
 
   this->type = rhs.type;
   delete this->_brain;
   if (rhs._brain == NULL)
       this->_brain = NULL;
   else
       this->_brain = new Brain(*rhs._brain);
   std::cout << "Cat assignation operator called" << std::endl;
   return *this;
}

void    Cat::makeSound(void) const{

    std::cout << "'Meow'" << std::endl;
    return ;
}

void    Cat::fillIdea(std::string idea, int index){

    if (index < 1 || index > 100)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    this->_brain->ideas[index - 1] = idea;
    return ;
}

void    Cat::displayIdeas(void) const{

    std::cout << std::endl;
    for (int i = 0; i < 100; i++)
        this->displayanIdea(i);
    std::cout << std::endl;
    return ;
}

void    Cat::displayanIdea(int index) const{
    
    if (index < 0 || index > 99)
    {
        std::cout << "Please provide index values between 1 and 100" << std::endl;
        return ;
    }
    std::cout << "Idea n " << index + 1 << " " << this->_brain->ideas[index] << std::endl; 
    return;
}
