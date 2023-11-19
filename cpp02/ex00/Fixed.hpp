#ifndef FIXED_H
# define FIXED_H
 
#include <iostream>

class Fixed
{
   public:
 
      Fixed(void);
      Fixed(Fixed const & src);
      ~Fixed(void);
 
      Fixed &  operator=(Fixed const & rhs);

      int   getRawBits(void) const;
      void  setrawBits(int const raw);
 
   private:

      int   _rawBits;
      static const int  _fractBits = 8;
};
#endif // FIXED_H

