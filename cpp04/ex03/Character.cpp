/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:26 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:27 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
 
Character::Character(void) : _name("Victor Newman"){

    for (int i = 0; i < 4; i++)
        _materiae[i] = NULL;
    std::cout << "Default Character Constructor called" << std::endl; 
    return ;
}

Character::Character(std::string name) : _name(name){

    for (int i = 0; i < 4; i++)
        _materiae[i] = NULL;
    std::cout << "Parametric Character Constructor called" << std::endl; 
    return ;
}

Character::Character(Character const & src) : _name(src.getName()){

    for (int i = 0; i < 4; i++)
    {
        if (src._materiae[i] != NULL)
            this->_materiae[i] = src._materiae[i]->clone();
        else
            this->_materiae[i] = NULL;
    }
    std::cout << "Copy Character Constructor called" << std::endl; 
    return ;
}
 
Character::~Character(void){

    for (int i = 0; i < 4; i++)
    {
        if (this->_materiae[i] != NULL)
            delete this->_materiae[i];
    }
    std::cout << "Default Character Destructor called" << std::endl; 
    return ;
}
 
Character & Character::operator=(Character const & rhs){

    this->_name = rhs.getName();
    for (int i = 0; i < 4; i++)
    {
        if (this->_materiae[i] != NULL)
        {
            delete this->_materiae[i];
            _materiae[i] = NULL;
        }
        if (rhs._materiae[i] != NULL)
            this->_materiae[i] = rhs._materiae[i]->clone();
    }
    std::cout << "Character assignation operator called" << std::endl;
    return *this;
}

std::string const & Character::getName(void) const{
    
    return this->_name;
}

void    Character::equip(AMateria* m){

    int i;
    for (i = 0; i < 4; i++)
    {
        if (this->_materiae[i] == NULL)
        {
            this->_materiae[i] = m;
            break;       
        }
    }
    if (i >= 4)
        std::cout << "Inventory of " << this->_name << " is full. Unequip materiae and try again." << std::endl;
    else
        std::cout << "Materia with type " << m->getType() << " has been equip in the slot " << i << " of " << this->_name << "'s inventory." << std::endl;
    return ;
}

void    Character::unequip(int idx){

    if (idx < 0 || idx > 3)
    {
        std::cout << "Index must be between 0 and 3, try again" << std::endl;
        return ;
    }
    int    i;
    for (i = 0; i < 4; i++)
    {
        if (i == idx)
        {
            std::cout << "Materia with type " << _materiae[i]->getType() << " has been unequiped from slot " << i << " of " << this->_name << "'s inventory." << std::endl;
            this->_materiae[i] = NULL;
            return ;
        }
    }
    std::cout << "No item has been unequiped from slot " << idx << ". It must already be empty" << std::endl;
}

void    Character::use(int idx, ICharacter& target){

    if (idx < 0 || idx > 3)
    {
        std::cout << "Index must be between 0 and 3, try again" << std::endl;
        return ;
    }
    if (this->_materiae[idx])
        this->_materiae[idx]->use(target);
    else
        std::cout << "Character " << this->_name << " does not have any equipment on slot " << idx << " ." << std::endl;
    return ;
}
