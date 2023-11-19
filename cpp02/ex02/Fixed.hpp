#ifndef FIXED_H
# define FIXED_H
 
#include <iostream>
#include <cmath>

class Fixed
{
   public:

      // Constructors
      
      Fixed(void);
      Fixed(int const i);
      Fixed(float const f);
      Fixed(Fixed const & src);

      // Destructors

      ~Fixed(void);
 
      // Comparison operators

      bool  operator>(Fixed const & rhs) const;
      bool  operator<(Fixed const & rhs) const;
      bool  operator>=(Fixed const & rhs) const;
      bool  operator<=(Fixed const & rhs) const;
      bool  operator==(Fixed const & rhs) const;
      bool  operator!=(Fixed const & rhs) const;

      // Arithmetic operators
      
      Fixed operator+(Fixed const & rhs) const;
      Fixed operator-(Fixed const & rhs) const;
      Fixed operator*(Fixed const & rhs) const;
      Fixed operator/(Fixed const & rhs) const;

      //Increment-Decrement operators

      Fixed operator++(void);
      Fixed operator--(void);
      Fixed operator++(int);
      Fixed operator--(int);

      //Assignation operator

      Fixed &  operator=(Fixed const & rhs);

      
      int   getRawBits(void) const;
      void  setrawBits(int const raw);


      float toFloat(void) const;
      int   toInt(void) const;
 

      static Fixed &   min(Fixed & lhs, Fixed & rhs);
      static Fixed const &   min(Fixed const & lhs, Fixed const & rhs);
      static Fixed &   max(Fixed & lhs, Fixed & rhs);
      static Fixed const &   max(Fixed const & lhs, Fixed const & rhs);

   private:

      int   _rawBits;
      static const int  _fractBits = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif // FIXED_H
