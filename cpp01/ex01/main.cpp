/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:30:01 by atardif           #+#    #+#             */
/*   Updated: 2023/12/12 17:50:15 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *zomb1 = zombieHorde(1000100, "Marc");
    if(!zomb1)
        return ((std::cout << "Allocation failed" << std::endl), 1);
    for (int i = 0; i < 30; i++)
        zomb1[i].announce();

    delete[] zomb1;
    return (0);
}
