#ifndef SAMPLE_H
# define SAMPLE_H
 
#include <iostream>
#include <string>

class Sample
{
   public:
 
      Sample(void);
      ~Sample(void);
 
    
      virtual void  greet(std::string value);
      virtual void  ungreet(std::string value);

   private:
};
#endif // SAMPLE_H
