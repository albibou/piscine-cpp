#ifndef ICE_H
# define ICE_H
 
#include "AMateria.hpp"
#include <string>
#include <iostream>


class Ice : public AMateria
{
    public:
 
       Ice(void);
       Ice(Ice const & src);
       ~Ice(void);
 
       Ice &  operator=(Ice const & rhs);

       virtual Ice* clone() const;
       virtual void use(ICharacter& target);

 
   protected:
 
   private:
 
};
#endif // ICE_H

