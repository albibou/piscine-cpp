/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:00:03 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 18:03:00 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class   Weapon{

    private :

        std::string _type;

    public :

        Weapon(void);
        ~Weapon(void);

        std::string const   &getType(void);
        void                setType(std::string);
};

#endif
