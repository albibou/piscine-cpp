#include "PmergeMe.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

PmergeMe::PmergeMe(void){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

PmergeMe::PmergeMe(PmergeMe const & rhs){

  *this = rhs;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

PmergeMe::~PmergeMe(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs){

  if (this != &rhs) 
  {
    _vec_to_sort = rhs._vec_to_sort;
    _deq_to_sort = rhs._deq_to_sort;
    _lis_to_sort = rhs._lis_to_sort;
  }
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

bool  PmergeMe::is_valid_int(const char * litteral) const {

  char    *tmp = NULL;
  double  num = strtod(litteral, &tmp);

  if (num < 0 || num > std::numeric_limits<int>::max())
    return false;
  std::string rest(tmp); 
  if (!rest.empty())
    return false;
  return true;
}

void  PmergeMe::print_vector(int range) const{
  
  if (!range)
    std::cout << "Numbers to sort :";
  else
    std::cout << "Call on groups of size " << range * 2 << std::endl;
  std::cout << "(";
  int i = 0;
  for (std::vector<int>::const_iterator it = _vec_to_sort.begin(); it != _vec_to_sort.end(); it++, i++){
    if (i % (range * 2) == 0 && i)
      std::cout << ")(";
    else if (i)
      std::cout << ",";
    std::cout << *it;
  }
  std::cout << ")" << std::endl << std::endl;
  return ;
}

void  PmergeMe::vec_swap_groups(std::vector<int>::iterator left, std::vector<int>::iterator right, int range){

  int tmp;

  for (int i = 0; i < range; i++, left--, right--){
    tmp = *right;
    *right = *left;
    *left = tmp;
  } 
}

void  PmergeMe::vec_merge_insertion(int range){

  std::vector<int>::iterator left = _vec_to_sort.begin() + range - 1;
  std::vector<int>::iterator right = _vec_to_sort.begin() + (range * 2) - 1;

  size_t  group_nbs = (_vec_to_sort.size() / range) / 2; 

  if (!group_nbs)
    return;
  for (size_t i = 0; i < group_nbs; i++, left += (range * 2), right += (range * 2)){
    if (*left > *right)
      vec_swap_groups(left, right, range);
  }
  print_vector(range);
  vec_merge_insertion(range * 2);
  return;
}

void  PmergeMe::sort_vector(char **args){
  
  for (size_t i = 0; args[i]; i++){

    if (!is_valid_int(args[i]))
      throw PmergeMe::ParsingError();
    _vec_to_sort.push_back(atoi(args[i]));
  }
  print_vector(0);
  _vec_time = clock();
  vec_merge_insertion(1);
  _vec_time = clock() - _vec_time;
  return ;
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

const char *  PmergeMe::ParsingError::what() const throw() {

  return "Error in a value, only use positive integers.";
}
