/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:57:23 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 15:57:24 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
 
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
   public:
 
      FragTrap(void);
      FragTrap(std::string name);
      FragTrap(FragTrap const & src);
      ~FragTrap(void);
 
      FragTrap &  operator=(FragTrap const & rhs);

      void  highFivesGuys(void);

 
   private:
};
#endif // FRAGTRAP_H

