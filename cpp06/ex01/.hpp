#ifndef CLASS_H
# define CLASS_H

# include <iostream>
# include <string>

# ifndef PRINT
#  define PRINT 0
# endif

class {

  public :

    (void);
    ( const & rhs);
    ~(void);

     & operator=( const & rhs);

  private :

};

std::ostream & operator<<(std::ostream & o,  const & rhs);

#endif
