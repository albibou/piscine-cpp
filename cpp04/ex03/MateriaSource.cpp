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

    for (int i = 0; i < 4; i++)
        this->_materiae[i] = NULL;
    std::cout << "Default MateriaSource Constructor called" << std::endl; 
    return ;
}
 
MateriaSource::MateriaSource(MateriaSource const & src){

    for (int i = 0; i < 4; i++)
    {
        if (src._materiae[i] != NULL)
            this->_materiae[i] = src._materiae[i]->clone();
        else
            this->_materiae[i] = NULL;
    }
    std::cout << "Copy MateriaSource Constructor called" << std::endl; 
    return ;
}
 
MateriaSource::~MateriaSource(void){

    for (int i = 0; i < 4; i++)
    {
        if (this->_materiae[i])
            delete this->_materiae[i];
    }
    std::cout << "Default MateriaSource Destructor called" << std::endl; 
    return ;
}
 
MateriaSource & MateriaSource::operator=(MateriaSource const & rhs){

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
    std::cout << "MateriaSource assignation operator called" << std::endl;
    return *this;
}

void    MateriaSource::learnMateria(AMateria *m){

    if (m == NULL)
    {
        std::cout << "MateriaSource can't learn from NULL materiae" << std::endl;
        return ;
    }
    int i;
    for (i = 0; i < 4; i++)
    {
        if (this->_materiae[i] == NULL)
        {
            this->_materiae[i] = m;
            break;       
        }
    }
    if (i == 4)
    {
        std::cout << "MateriaSource is full." << std::endl;
        delete m;
    }
    else
        std::cout << "Materia with type " << m->getType() << " has been learned." << std::endl;
    return ;
}

AMateria * MateriaSource::createMateria(std::string const & type){

    int i;
    for (i = 0; i < 4; i++)
    {
        if (this->_materiae[i] != NULL && this->_materiae[i]->getType() == type)
            return (this->_materiae[i]->clone());
    }
    std::cout << "No Materia with the type : " << type << " has been found in MateriaSource." << std::endl;
    return (NULL);
}
