/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:57:14 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:57:15 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
 
#include <iostream>
#include <string>

class ClapTrap
{
   public:
 
      ClapTrap(void);
      ClapTrap(std::string name);
      ClapTrap(ClapTrap const & src);
      ~ClapTrap(void);
 
      ClapTrap &  operator=(ClapTrap const & rhs);
 
      void  attack(const std::string& target);
      void  takeDamage(unsigned int amount);
      void  beRepaired(unsigned int amount);

   protected:

      std::string   name;
      unsigned int   hitPoints;
      unsigned int   energyPoints;
      unsigned int   attackDamage;
};
#endif // CLAPTRAP_H

