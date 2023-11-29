/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:25:08 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 19:09:30 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <string>
# include <iostream>

class   HumanA{

    private :

        std::string _name;
        Weapon     *_weapon;

    public :

        HumanA(std::string name, Weapon& weapon);
        ~HumanA(void);

        void    attack(void);

};

#endif
