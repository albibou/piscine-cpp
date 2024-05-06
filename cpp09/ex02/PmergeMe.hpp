#ifndef PMERGEME_H
# define PMERGEME_H 

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <vector>
# include <list>
# include <deque>

# ifndef PRINT
#  define PRINT 0
# endif

class PmergeMe{

  public :

    PmergeMe(void);
    PmergeMe(PmergeMe const & rhs);
    ~PmergeMe(void);

    PmergeMe & operator=(PmergeMe const & rhs);

    bool  is_valid_int(const char * litteral) const;

    void  print_vector(int range) const;

    void  vec_swap_groups(std::vector<int>::iterator left, std::vector<int>::iterator right, int range);
    void  vec_merge_insertion(int range);
    void  sort_vector(char **args);
    void  sort_deque(char **args);
    void  sort_lis(char **args);

    class ParsingError : public std::exception {

      public :
        const char * what() const throw();
    };

  private :

    std::vector<int>  _vec_to_sort;
    std::deque<int>   _deq_to_sort;
    std::list<int>    _lis_to_sort;
    
    clock_t           _vec_time;
    clock_t           _deq_time;
    clock_t           _lis_time;


};

#endif
