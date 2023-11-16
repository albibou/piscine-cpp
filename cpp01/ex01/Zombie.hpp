/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:55:11 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 17:41:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class   Zombie{

    private :

        std::string _name;

    public :

        Zombie(void);
        ~Zombie(void);

        void    announce(void);
        void    set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
