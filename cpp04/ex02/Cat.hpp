#ifndef CAT_H
# define CAT_H
 
#include "Aanimal.hpp"
#include "Brain.hpp"

class Cat : public Aanimal
{
   public:
 
      Cat(void);
      Cat(Cat const & src);
      ~Cat(void);
 
      Cat &  operator=(Cat const & rhs);
 
      void  makeSound(void) const;
      void  fillIdea(std::string idea, int index);
      void  displayIdeas(void) const;
      void  displayanIdea(int index) const;

   private:

      Brain *_brain;
};
#endif // CAT_H
