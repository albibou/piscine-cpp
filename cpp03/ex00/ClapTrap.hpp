/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:54:56 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:56:12 by atardif          ###   ########.fr       */
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

   private:

      std::string   _name;
      unsigned int   _hitPoints;
      unsigned int   _energyPoints;
      unsigned int   _attackDamage;
};
#endif // CLAPTRAP_H

