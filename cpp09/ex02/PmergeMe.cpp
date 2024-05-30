#ifndef PMERGEME_CPP
# define PMERGEME_CPP

# include "PmergeMe.hpp"

////////////////////////////////////////////////////////////////////
///                 Constructors, Destructors                    ///
////////////////////////////////////////////////////////////////////

template <template<typename, typename> class Container>
PmergeMe<Container>::PmergeMe(void){

  if (PRINT)
    std::cout << "Default constructor called" << std::endl;
  return ;
} 

template <template<typename, typename> class Container>
PmergeMe<Container>::PmergeMe(PmergeMe<Container> const & rhs){

  *this = rhs;
  if (PRINT)
    std::cout << "Copy constructor called" << std::endl;
  return ;
}

template <template<typename, typename> class Container>
PmergeMe<Container>::~PmergeMe<Container>(void){

  if (PRINT)
    std::cout << "Default destructor called" << std::endl;
  return;
}

////////////////////////////////////////////////////////////////////
///                       Operator overloads                     ///
////////////////////////////////////////////////////////////////////

template <template<typename, typename> class Container>
PmergeMe<Container> & PmergeMe<Container>::operator=(PmergeMe<Container> const & rhs){

  if (this != &rhs) 
    _to_sort = rhs._to_sort;
  if (PRINT)
    std::cout << "Assignation operator called" << std::endl;
  return *this;
}

////////////////////////////////////////////////////////////////////
///                        Methods                               ///
////////////////////////////////////////////////////////////////////

template <template<typename, typename> class Container>
void  PmergeMe<Container>::print_container(std::string moment) {

  std::cout << moment;
  for (typename Container<int, std::allocator<int> >::iterator it = _to_sort.begin(); it != _to_sort.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  return ;
}

template <template<typename, typename> class Container>
void  PmergeMe<Container>::print_time_to_sort(std::string type) const{
  
  double time = static_cast<double>(_sort_time / CLOCKS_PER_SEC) * 1000000;
  std::cout << "Time to process a range of " << _to_sort.size() << " elements with std::" <<
    type << " : " << time << "ms" << std::endl;
  return ;
}

template <template<typename, typename> class Container>
bool  PmergeMe<Container>::is_valid_int(const char * litteral) const {

  char    *tmp = NULL;
  double  num = strtod(litteral, &tmp);

  if (num < 0 || num > std::numeric_limits<int>::max())
    return false;
  std::string rest(tmp); 
  if (!rest.empty())
    return false;
  return true;
}

template <template<typename, typename> class Container>
size_t  PmergeMe<Container>::find_position_in_container(std::vector<int> & vec, int target, int mode){

  if (mode == 1)
    return (std::distance(vec.begin(), std::find(vec.begin(), vec.end(), target)));
  else
    return (std::distance(_to_sort.begin(), std::find(_to_sort.begin(), _to_sort.end(), target)));
}

template <template<typename, typename> class Container>
void  PmergeMe<Container>::swap_groups(typename Container<int, std::allocator<int> >::iterator left, typename Container<int, std::allocator<int> >::iterator right, int range){

  int tmp;

  for (int i = 0; i < range; i++, left--, right--){
    tmp = *right;
    *right = *left;
    *left = tmp;
  } 
}

template <template<typename, typename> class Container>
size_t  PmergeMe<Container>::get_Jacobstahl_Number(bool restart){

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

template <template<typename, typename> class Container>
void  PmergeMe<Container>::fill_chains(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t range){

  typename Container<int, std::allocator<int> >::iterator it = _to_sort.begin() + range - 1;

  for (size_t i = range - 1; i < _to_sort.size(); it += range, i += range){
    if (i < 2 * range || i / range % 2)
      main_chain.push_back(*it);
    else 
      pending_chain.push_back(*it);
  }
  return;
}

template <template<typename, typename> class Container>
size_t PmergeMe<Container>::find_index_max(int target, int range, std::vector<int> & main_chain){

  int prev_index = _to_sort[find_position_in_container(main_chain, target, 0) - range];

  return find_position_in_container(main_chain, prev_index, 1);
}

template <template<typename, typename> class Container>
size_t  PmergeMe<Container>::binary_search(std::vector<int> & main_chain, int target, size_t index_max){

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

template <template<typename, typename> class Container>
void  PmergeMe<Container>::insert_a_number(size_t index_to, size_t index_from, size_t range){

  int number;

  for (size_t i = 0; i < range; i++){
    number = _to_sort[index_from];
    _to_sort.insert(_to_sort.begin() + index_to, number);
    if (index_to < index_from)
      _to_sort.erase(_to_sort.begin() + index_from + 1);
    else {
      _to_sort.erase(_to_sort.begin() + index_from);
      index_from--;
      index_to--;
    }
  }
  return ;
}

template <template<typename, typename> class Container>
void  PmergeMe<Container>::insertions(std::vector<int> & main_chain, std::vector<int> & pending_chain, size_t jacobstahl, size_t range){

  int index = jacobstahl;
  size_t  main_chain_position, index_max, index_to, index_from;

  if (static_cast<size_t>(index) >= pending_chain.size())
    index = pending_chain.size() - 1;
  index_max = find_index_max(pending_chain[index], range, main_chain);
  while (index > -1){
    main_chain_position = binary_search(main_chain, pending_chain[index], index_max); 
    if (main_chain_position == main_chain.size()){
      index_to = find_position_in_container(main_chain, main_chain[main_chain_position - 1], 0) + range + 1;
    }
    else{
      index_to = find_position_in_container(main_chain, main_chain[main_chain_position], 0) + 1;
    }
    if (static_cast<int>(index_to - range) >= 0)
      index_to -= range;
    index_from = find_position_in_container(main_chain, pending_chain[index], 0); 
    insert_a_number(index_to, index_from, range); 
    main_chain.insert(main_chain.begin() + (main_chain_position), pending_chain[index]); 
    pending_chain.erase(pending_chain.begin() + index); 
    index--;
  }
  return;
}

template <template<typename, typename> class Container>
void  PmergeMe<Container>::setup_insertions(int range){

  std::vector<int> main_chain;
  std::vector<int> pending_chain;
  size_t jacobstahl = get_Jacobstahl_Number(true);

  fill_chains(main_chain, pending_chain, range);
  while(!pending_chain.empty()){
    insertions(main_chain, pending_chain, jacobstahl, range);
    jacobstahl = get_Jacobstahl_Number(false) - 1;
  }
  return ;
}

template <template<typename, typename> class Container>
void  PmergeMe<Container>::merge_insertion(int range){

  typename Container<int, std::allocator<int> >::iterator left = _to_sort.begin() + range - 1;
  typename Container<int, std::allocator<int> >::iterator right = _to_sort.begin() + (range * 2) - 1;

  size_t  group_nbs = (_to_sort.size() / range) / 2; 

  if (!group_nbs)
    return;
  for (size_t i = 0; i < group_nbs; i++, left += (range * 2), right += (range * 2)){
    if (*left > *right)
      swap_groups(left, right, range);
  }
  merge_insertion(range * 2);
  setup_insertions(range);
  return;
}

template <template<typename, typename> class Container>
void  PmergeMe<Container>::sort_container(char **args, int print){
  
  int num = 0;
  typename Container<int, std::allocator<int> >::iterator it;

  for (size_t i = 0; args[i]; i++){

    if (!is_valid_int(args[i]))
      throw PmergeMe<Container>::ParsingError();
    num = atoi(args[i]);
    it = std::find(_to_sort.begin(), _to_sort.end(), num);
    if (it != _to_sort.end())
      throw PmergeMe<Container>::DoubleValue();
    _to_sort.push_back(num);
  }
  if (print == PRINT_CONTAINER)
    print_container("Before: ");
  _sort_time = clock();
  merge_insertion(1);
  if (print == PRINT_CONTAINER)
  print_container("After: ");
  _sort_time = clock() - _sort_time;
  return ;
}

////////////////////////////////////////////////////////////////////
///                        Exceptions                            ///
////////////////////////////////////////////////////////////////////

template <template<typename, typename> class Container>
const char *  PmergeMe<Container>::ParsingError::what() const throw() {

  return "Error in a value, only use positive integers.";
}

template <template<typename, typename> class Container>
const char *  PmergeMe<Container>::DoubleValue::what() const throw() {

  return "Error in a value, integer list can't contain duplicates.";
}

#endif
