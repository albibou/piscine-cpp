/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:25:06 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 18:48:14 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class   HumanB{

    private :

        std::string _name;
        Weapon  *_weapon;

    public :

        HumanB(std::string name);
        ~HumanB(void);

        void    attack(void);
        void    setWeapon(Weapon& weapon);

};

#endif
