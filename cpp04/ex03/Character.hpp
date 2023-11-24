#ifndef CHARACTER_H
# define CHARACTER_H
 
#include "AMateria.hpp"

class Character
{
    public:
 
       Character(void);
       Character(Character const & src);
       ~Character(void);
 
       Character &  operator=(Character const & rhs);
 
   protected:
 
   private:
 
       AMateria    *_materiae[4];
};
#endif // CHARACTER_H

