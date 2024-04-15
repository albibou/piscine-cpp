#ifndef CLASS_H
# define CLASS_H

# include <iostream>
# include <string>

# ifndef PRINT
#  define PRINT 0
# endif

template <typename T>

class Array{

  public :

    Array(void);
    Array(unsigned int size);
    Array(Array const & rhs);
    ~Array(void);

    Array & operator=(Array const & rhs) const;
    T & operator[](unsigned int index) const;


    unsigned int  size(void)const;

  private :

    T*  elements;
    const unsigned int _size;

};


#endif
