/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:06:38 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 17:24:48 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *zomb1 = newZombie("Robert");

    zomb1->announce();

    randomChump("Marc");
    delete zomb1;
    return (0);
}
