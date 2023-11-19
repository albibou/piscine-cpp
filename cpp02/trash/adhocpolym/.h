#ifndef SAMPLE_H
# define SAMPLE_H
 
#include <iostream>
#include <string>

class Sample
{
   public:
 
      Sample();
      ~Sample();

      void  test(char const c) const;
      void  test(int const i) const;
      void  test(float const f) const;
      void  test(Sample const &y) const;
 
   private:
};

#endif // SAMPLE_H
