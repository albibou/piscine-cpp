#ifndef SUB_H
# define SUB_H
 
#include "Sample.hpp"

class Sub : public Sample
{
   public:
 
      Sub(void);
      ~Sub(void);
 

      virtual void  greet(std::string value);
      virtual void  ungreet(std::string value);
 
   private:
};
#endif // SUB_H
