#ifndef FIXED_H
# define FIXED_H
 
class Fixed
{
   public:
 
      Fixed(void);
      Fixed(Fixed const & src);
      ~Fixed(void);
 
      Fixed &  operator=(Fixed const & rhs);
 
   private:
};
#endif // FIXED_H

