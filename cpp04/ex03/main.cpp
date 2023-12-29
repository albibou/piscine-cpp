/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:14:22 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:14:23 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main(void)
{
    Character   char1;
    Character   char2("Jack Abott");

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            char1.equip(new Ice());
        else
            char1.equip(new Cure());
    }
    for (int i = 0; i < 6; i++)
        char1.use(i, char2);


    return(0);
}

