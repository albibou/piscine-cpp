/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:29:58 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 17:38:59 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){

    Zombie *zombie = new Zombie[N];

    if (!zombie)
        return (NULL);
    for (int i = 0; i < N; i++)
        zombie[i].set_name(name);
    return (zombie);
}
