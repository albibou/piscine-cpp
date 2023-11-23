#ifndef BRAIN_H
# define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
   public:
 
      Brain(void);
      Brain(Brain const & src);
      ~Brain(void);
 
      Brain &  operator=(Brain const & rhs);

      std::string   ideas[100];

   private:

      //std::string   _ideas[100];

};
#endif // BRAIN_H

