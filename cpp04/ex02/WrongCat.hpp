#ifndef WRONGCAT_H
# define WRONGCAT_H
 
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
   public:
 
      WrongCat(void);
      WrongCat(WrongCat const & src);
      ~WrongCat(void);
 
      WrongCat &  operator=(WrongCat const & rhs);
 
      void  makeSound(void) const;
   private:
};
#endif // WRONGCAT_H

