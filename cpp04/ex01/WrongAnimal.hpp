#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include "Animal.hpp"

class WrongAnimal
{
   public:
 
      WrongAnimal(void);
      WrongAnimal(std::string name);
      WrongAnimal(WrongAnimal const & src);
      virtual ~WrongAnimal(void);
 
      WrongAnimal &  operator=(WrongAnimal const & rhs);
 
      virtual void  makeSound(void) const;
      std::string   getType(void) const;
      
   protected :

      std::string   type;

   private:
};
#endif // WRONGANIMAL_H

