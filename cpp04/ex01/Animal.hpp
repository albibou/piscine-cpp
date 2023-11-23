#ifndef ANIMAL_H
# define ANIMAL_H
 
#include <iostream>
#include <string>

class Animal
{
   public:
 
      Animal(void);
      Animal(std::string name);
      Animal(Animal const & src);
      virtual ~Animal(void);
 
      Animal &  operator=(Animal const & rhs);

      std::string   getType(void) const;
      virtual void  makeSound(void) const;

   protected :

      std::string   type;
 
   private:
};

#endif // ANIMAL_H

