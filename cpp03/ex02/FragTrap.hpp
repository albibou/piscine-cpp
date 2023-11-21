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

      void  attack(const std::string& target);
      void  takeDamage(unsigned int amount);
      void  beRepaired(unsigned int amount);
      void  highFivesGuys(void);

 
   private:
};
#endif // FRAGTRAP_H

