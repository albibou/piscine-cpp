#ifndef CURE_H
# define CURE_H
 
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
 
       Cure(void);
       Cure(Cure const & src);
       ~Cure(void);
 
       Cure &  operator=(Cure const & rhs);

       virtual Cure* clone() const;
       virtual void use(ICharacter& target);
 
   protected:
 
   private:
 
};
#endif // CURE_H

