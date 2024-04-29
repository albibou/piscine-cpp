#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <set>
# include <deque>
# include <list>
# include <limits.h>
# include <fstream>

# define SHORT_SPAN "Shortest Span : "
# define LONG_SPAN "Longest Span : "

# ifndef PRINT
#  define PRINT 0
# endif

class Span{

  public :
  
    Span(void);
    Span (const unsigned int N);
    Span(Span const & rhs);
    ~Span(void);

    Span & operator=(Span const & rhs);

    void  addNumber(int number);
    template <typename Iterator>
    void  addManyNumbers(Iterator begin, Iterator end){

      for (Iterator it = begin; it != end; it++)
        addNumber(*it);
    } 

    unsigned int getSize(void) const;
    unsigned int getMaxCapacity(void) const;
    const std::set<int>& getSet(void) const;

    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);

    class TooManyNumbers : public std::exception {
      public :
        const char * what() const throw();
    };

    class NotEnoughNumbers : public std::exception {
      public :
        const char * what() const throw();
    };

  private :

    std::set<int> _numbers;
    unsigned int  _maxCapacity;

};

std::ostream & operator<<(std::ostream & o, Span const & rhs);

#endif
