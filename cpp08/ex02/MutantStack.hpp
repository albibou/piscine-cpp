#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <string>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# include <stack>
# include <deque>
# include <vector>

# ifndef PRINT
#  define PRINT 0
# endif

template <typename T>

class MutantStack : public std::stack<T>{

  public :

    MutantStack(void) {return ;}
    MutantStack(MutantStack const & rhs) {*this = rhs;}
    ~MutantStack(void) {return ;}

    MutantStack & operator=(MutantStack const & rhs){
      if (*this != rhs){
        *this = rhs;
      }
      return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin(){return this->c.begin();}
    iterator end(){return this->c.end();}

    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const {return this->c.begin();}
    const_iterator end() const {return this->c.end();}

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin(){return this->c.rbegin();}
    reverse_iterator rend(){return this->c.rend();}

    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rbegin() const {return this->c.rbegin();}
    const_reverse_iterator rend() const {return this->c.rend();}

};

#endif
