#ifndef DOG_H
# define DOG_H
 
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
   public:
 
      Dog(void);
      Dog(Dog const & src);
      ~Dog(void);
 
      Dog &  operator=(Dog const & rhs);
 
      void  makeSound(void) const;
      void  fillIdea(std::string idea, int index);
      void  displayIdeas(void) const;
      void  displayanIdea(int index) const;

   private:

      Brain *_brain;
};
#endif // DOG_H

