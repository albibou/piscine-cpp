/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:54:35 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:54:36 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    clap("Abott");
    ClapTrap    clap2("Newman");

    std::cout << std::endl;

    clap.attack("Newman");
    clap2.takeDamage(0);

    clap.beRepaired(1000);
    for (int i = 0; i < 15; i++)
        clap.attack("Newman");

    std::cout << std::endl;
    return (0);
}
