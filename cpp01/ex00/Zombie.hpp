/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:55:11 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 17:21:35 by atardif          ###   ########.fr       */
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

        Zombie(std::string str);
        ~Zombie(void);

        void    announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
