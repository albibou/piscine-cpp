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
    if (i && range && i % (range * 2) == 0)
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

size_t  PmergeMe::get_Jacobstahl_Number(bool restart){

  static size_t antePenultimate = 0;
  static size_t number = 1;

  if (restart){
    antePenultimate = 0;
    number = 1;
  }
  int tmp = antePenultimate;
  antePenultimate = number;
  number = 2 * tmp + number;
  return (number);
}

size_t  PmergeMe::find_position_in_vector(std::vector<int> & vec, int target){

  return (std::distance(vec.begin(), std::find(vec.begin(), vec.end(), target)));
}

void  PmergeMe::fill_chains(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t range){

  std::vector<int>::iterator it = _vec_to_sort.begin() + range - 1;

  for (size_t i = range - 1; i < _vec_to_sort.size(); it += range, i += range){
    if (i < 2 * range || i / range % 2)
      main_chain.push_back(*it);
    else 
      pending_chain.push_back(*it);
  }
  return;
}

size_t  PmergeMe::vec_binary_search(std::vector<int> & main_chain, int target, size_t index_max){

  size_t index_min = 0;
  size_t index_med;

  while(index_min + 1 != index_max){
    index_med = (index_min + index_max) / 2;
    if (main_chain[index_med] > target)
      index_max = index_med;
    else 
      index_min = index_med;
  }
  if (main_chain[index_max] < target)
    return index_max + 1;
  else if (main_chain[index_min] > target)
    return index_min;
  else 
    return index_max;
}

void  PmergeMe::vec_insert_a_number(size_t index_to, size_t index_from, size_t range){

  int number;

  for (size_t i = 0; i < range; i++){
    number = _vec_to_sort[index_from];
    _vec_to_sort.insert(_vec_to_sort.begin() + index_to, number);
    if (index_to < index_from)
      _vec_to_sort.erase(_vec_to_sort.begin() + index_from + 1);
    else {
      _vec_to_sort.erase(_vec_to_sort.begin() + index_from);
      index_from--;
      index_to--;
    }
  }
  return ;
}

void  PmergeMe::vec_insertions(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t jacobstahl, size_t range){

  int index = jacobstahl;
  size_t  main_chain_position, index_max, index_to, index_from;

  if (static_cast<size_t>(index) >= pending_chain.size())
    index = pending_chain.size() - 1;
  index_max = find_index_max(pending_chain[index], range, main_chain);
  while (index > -1){
    main_chain_position = vec_binary_search(main_chain, pending_chain[index], index_max); 
    if (main_chain_position == main_chain.size()){
      index_to = find_position_in_vector(_vec_to_sort, main_chain[main_chain_position - 1]) + range + 1;
    }
    else{
      index_to = find_position_in_vector(_vec_to_sort, main_chain[main_chain_position]) + 1;
    }
    if (static_cast<int>(index_to - range) >= 0)
      index_to -= range;
    index_from = find_position_in_vector(_vec_to_sort, pending_chain[index]); 
    vec_insert_a_number(index_to, index_from, range); 
    main_chain.insert(main_chain.begin() + (main_chain_position), pending_chain[index]); 
    pending_chain.erase(pending_chain.begin() + index); 
    index--;
  }
  return;
}

size_t PmergeMe::find_index_max(int target, int range, std::vector<int> & main_chain){

  int prev_index = _vec_to_sort[find_position_in_vector(_vec_to_sort, target) - range];

  return find_position_in_vector(main_chain, prev_index);
}

void  PmergeMe::vec_setup_insertions(int range){

  std::vector<int> main_chain;
  std::vector<int> pending_chain;
  size_t jacobstahl = get_Jacobstahl_Number(true);

  fill_chains(main_chain, pending_chain, range);
  while(!pending_chain.empty()){
    vec_insertions(main_chain, pending_chain, jacobstahl, range);
    jacobstahl = get_Jacobstahl_Number(false) - 1;
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
  vec_setup_insertions(range);

  //insertion(_vec_to_sort, range); 
  print_vector(range);
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
