/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:57:02 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:57:03 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap    clap("Abott");
    ClapTrap    clap2("Newman");
    ClapTrap    clap3(clap2);

    std::cout << std::endl;

    clap.attack("Newman");
    clap3.takeDamage(0);
    clap.beRepaired(1000);

    std::cout << std::endl;

    ScavTrap    scav("Williams");
    ScavTrap    scav2("Romalotti");
    ScavTrap    scav3(scav2);

    std::cout << std::endl;

    scav.attack("Romalotti");
    scav3.takeDamage(20);
    scav3.beRepaired(21);
    for(int i = 0; i < 51; i++)
        scav2.guardGate();

    std::cout << std::endl;

    FragTrap    frag("Baldwin");
    FragTrap    frag2("Chancelor");
    FragTrap    frag3(frag2);

    std::cout << std::endl;

    frag.attack("Chancelor");
    frag3.highFivesGuys();
    frag3.takeDamage(30);
    frag3.beRepaired(10);
    frag3.takeDamage(30);
    frag3.takeDamage(30);
    frag3.takeDamage(30);
    frag3.highFivesGuys();

    std::cout << std::endl;
    return (0);
}
