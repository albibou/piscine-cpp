#ifndef PMERGEME_H
# define PMERGEME_H 

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

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


    size_t  get_Jacobstahl_Number(bool restart);
    size_t  find_position_in_vector(std::vector<int> & vec, int target);
    void  fill_chains(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t range);

    void  vec_swap_groups(std::vector<int>::iterator left, std::vector<int>::iterator right, int range);


    void  vec_insert_a_number(size_t index_to, size_t index_from, size_t range);
    size_t  vec_binary_search(std::vector<int> & main_chain, int target, size_t index_max);
    void  vec_insertions(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t jacobstahl, size_t index_max, size_t range);

    size_t find_index_max(int target, int range, std::vector<int> & main_chain);
    void  vec_setup_insertions(int range);
    void  vec_merge_insertion(int range);
    void  sort_vector(char **args);
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
