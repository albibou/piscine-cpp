#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <string>
# include <stdint.h>

# ifndef PRINT
#  define PRINT 0
# endif

struct  Data{

  int num;
  std::string str;
};

class Serializer{

  public :

    ~Serializer(void);

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);


  private :

    Serializer(void);
    Serializer(Serializer const & rhs);
    Serializer & operator=(Serializer const & rhs);
};

std::ostream & operator<<(std::ostream & o, Serializer const & rhs);

#endif
