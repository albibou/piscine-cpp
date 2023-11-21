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

