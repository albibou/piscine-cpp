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
    std::cout << "Appel des contructeurs : " << std::endl;
    ClapTrap    clap("Abott");
    ClapTrap    clap2("Newman");

    std::cout << std::endl << "Tests des fonctions membres : " << std::endl;

    clap.attack("Newman");
    clap2.takeDamage(0);
    clap.beRepaired(1000);

    std::cout << std::endl << "Test des points d'energie : " << std::endl;
    for (int i = 0; i < 15; i++)
        clap.attack("Newman");

    std::cout << std::endl << "Appel des destructeurs : " << std::endl;
    return (0);
}
