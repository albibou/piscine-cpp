#ifndef PMERGEME_H
# define PMERGEME_H 

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <ctime>
# include <limits>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

# ifndef PRINT
#  define PRINT 0
#  define PRINT_CONTAINER 1
#  define NO_PRINT_CONTAINER 2
# endif

template <template<typename, typename> class Container>
class PmergeMe{

  public :

    PmergeMe(void);
    PmergeMe(PmergeMe const & rhs);
    ~PmergeMe(void);

    PmergeMe & operator=(PmergeMe const & rhs);

    void    print_container(std::string moment);
    void    print_time_to_sort(std::string type) const;
    void    sort_container(char **args, int print);

  private :

    Container<int, std::allocator<int> >  _to_sort;
    clock_t          _sort_time;

    bool    is_valid_int(const char * litteral) const;

    size_t  find_position_in_container(std::vector<int> & vec, int target, int mode);
    void    swap_groups(typename Container<int, std::allocator<int> >::iterator left, typename Container<int, std::allocator<int> >::iterator right, int range);

    size_t  get_Jacobstahl_Number(bool restart);
    void    fill_chains(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t range);
    size_t  binary_search(std::vector<int> & main_chain, int target, size_t index_max);
    size_t  find_index_max(int target, int range, std::vector<int> & main_chain);

    void    insert_a_number(size_t index_to, size_t index_from, size_t range);
    void    insertions(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t jacobstahl, size_t range);
    void    setup_insertions(int range);
    void    merge_insertion(int range);

    class ParsingError : public std::exception {

      public :
        const char * what() const throw();
    };

    class DoubleValue : public std::exception {

      public :
        const char * what() const throw();
    };
};

# include "PmergeMe.cpp"

#endif
