/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:56:45 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:56:46 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
 
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
   public:
 
      ScavTrap(void);
      ScavTrap(std::string name);
      ScavTrap(ScavTrap const & src);
      ~ScavTrap(void);
 
      ScavTrap &  operator=(ScavTrap const & rhs);
      
      void  attack(const std::string& target);
      void  takeDamage(unsigned int amount);
      void  beRepaired(unsigned int amount);
      void  guardGate(void);

   private:
};
#endif // SCAVTRAP_H

