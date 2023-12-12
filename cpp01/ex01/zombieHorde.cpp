/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:29:58 by atardif           #+#    #+#             */
/*   Updated: 2023/12/12 16:43:52 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){

    if (N <= 0 || N > 100000)
    {
        std::cout << "You only can allocate between 1 and 100000 zombies" << std::endl;
        return NULL;
    }
    Zombie *zombie = new Zombie[N];

    if (!zombie)
        return (NULL);
    for (int i = 0; i < N; i++)
        zombie[i].set_name(name);
    return (zombie);
}
