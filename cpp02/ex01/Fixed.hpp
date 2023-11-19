#ifndef FIXED_H
# define FIXED_H
 
#include <iostream>
#include <cmath>

class Fixed
{
   public:
 
      Fixed(void);
      Fixed(int const i);
      Fixed(float const f);
      Fixed(Fixed const & src);
      ~Fixed(void);
 
      Fixed &  operator=(Fixed const & rhs);

      int   getRawBits(void) const;
      void  setrawBits(int const raw);
      float toFloat(void) const;
      int   toInt(void) const;
 
   private:

      int   _rawBits;
      static const int  _fractBits = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif // FIXED_H
