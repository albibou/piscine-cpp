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
      int   hitPoints;
      int   energyPoints;
      int   attackDamage;
};
#endif // CLAPTRAP_H

