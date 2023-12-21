/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:56:22 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:56:51 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "Appel des contructeurs de ClapTrap : " << std::endl;
    ClapTrap    clap("Abott");
    ClapTrap    clap2("Newman");
    ClapTrap    clap3(clap2);

    std::cout << std::endl << "Tests des fonctions membres de ClapTrap : " << std::endl;

    clap.attack("Newman");
    clap3.takeDamage(0);
    clap.beRepaired(1000);

    std::cout << std::endl << "Appel des constructeurs de ScavTrap :" << std::endl;

    ScavTrap    scav("Williams");
    ScavTrap    scav2("Romalotti");
    ScavTrap    scav3(scav2);

    std::cout << std::endl << "Appel des fonctions membres propres a ScavTrap : " << std::endl;

    scav2.guardGate();
    scav.attack("Romalotti");

    std::cout << std::endl << "Appel des fonctions membres heritees de ClapTrap : " << std::endl;

    scav3.takeDamage(20);
    scav3.beRepaired(21);

    std::cout << std::endl << "Test des points de vie : " << std::endl;
    for (int i = 0; i < 6; i++)
    {
        scav.attack("Romalotti");
        scav3.takeDamage(20);
    }
    scav3.guardGate();

    std::cout << std::endl << "Appel des destructeurs" << std::endl;
    return (0);
}
