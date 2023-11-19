#ifndef SAMPLE_H
# define SAMPLE_H
 
#include <iostream>
#include <string>

class Sample
{
   public:
 
      Sample(void); // Default Constructor -> Canonical
      Sample(int const n);
      Sample(Sample const & src); // Copy Constructor -> Canonical
      ~Sample(void); // Default Destructor -> Canonical

      Sample &  operator=(Sample const & rhs);

      int   getValue(void) const;
 
   private:

      int   _foo;
};

std::ostream &    operator<<(std::ostream & o, Sample const & rhs);

#endif // SAMPLE_H

