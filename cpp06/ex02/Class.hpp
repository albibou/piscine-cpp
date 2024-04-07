#ifndef CLASS_H
# define CLASS_H

# include <iostream>
# include <cstdlib>

# ifndef PRINT
#  define PRINT 0
# endif

class Base{

  public :

    virtual ~Base(void) {};

  private :

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
