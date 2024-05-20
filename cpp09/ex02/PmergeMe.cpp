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



int getMultipleOfTwo(bool refresh)
{
	static int nbr = 4;

	if (refresh)
		nbr = 4;
	int	to_return = nbr;
	nbr *= 2;
	return (to_return);
}

int getDuoJacobsthalNbr(bool refresh)
{
	static int js = 1;
	static int jsLast = 3;
	
	if (refresh)
	{
		js = 1;
		jsLast = 3;
	}
	int	to_return = jsLast - js;
	int	tmp = js;
	js = jsLast;
	jsLast = to_return + 2 * tmp;
	return (to_return);		
}


void	updateIndex(size_t min, size_t max, std::vector<size_t> & vect, int range)
{
	size_t	size = vect.size();

	for (size_t i = 0; i < size; ++i)
	{
		if (vect[i] > max)
			return ;
		else if (vect[i] >= min)
			vect[i] += range;
	}
}

// ************************************************************************** //
//	INSERTION PART
// ************************************************************************** //

size_t	whereInsert(std::vector<int> & v, std::vector<size_t>& sortedIndexes, int nbrToInsert, int indexMax)
{
	int	indexMin = 0;
	int indexMid;

	if (indexMax + 1 > static_cast<int>(sortedIndexes.size()))
		indexMax = sortedIndexes.size() - 1;
	

	while (indexMin + 1 != indexMax)
	{
		indexMid = indexMin + (indexMax - indexMin) / 2;
		if (v[sortedIndexes[indexMid]] < nbrToInsert)
			indexMin = indexMid;
		else
			indexMax = indexMid;
	}
	if (v[sortedIndexes[indexMin]] > nbrToInsert)
		return (sortedIndexes[indexMin]);
	if (v[sortedIndexes[indexMax]] < nbrToInsert)
		return (sortedIndexes[indexMax] + sortedIndexes[0] + 1);
	if (sortedIndexes[indexMax] - sortedIndexes[indexMin] == sortedIndexes[0] + 1)
		return (sortedIndexes[indexMax]);
	return (sortedIndexes[indexMax] - sortedIndexes[0] - 1);
}


void	insertion(std::vector<int> & nbrs, size_t range) {

	std::vector<size_t> sortedIndexes;
	std::vector<size_t> unsortedIndexes;
	size_t	size = nbrs.size();

	for (size_t i = range - 1; i < size; i += range)
	{
		if (i < 2 * range || i / range % 2)
			sortedIndexes.push_back(i);
		else
			unsortedIndexes.push_back(i);
	}

	int		duoJacobsthalNbr = getDuoJacobsthalNbr(true);
	int		indexMax = getMultipleOfTwo(true) - 1;
	size_t	whereInsertMe, whereImFrom;

	while (unsortedIndexes.empty() == false)
	{
		for (int ind = std::min(duoJacobsthalNbr, static_cast<int>(unsortedIndexes.size())) - 1; ind > -1; --ind)
		{
			whereInsertMe = whereInsert(nbrs, sortedIndexes, nbrs[unsortedIndexes[ind]], indexMax);
			whereImFrom = unsortedIndexes[ind];
			for (size_t j = 0; j < range; j++)
			{
				nbrs.insert(nbrs.begin() + whereInsertMe - range + 1, nbrs[whereImFrom]);
				nbrs.erase(nbrs.begin() + whereImFrom + 1);
			}
			unsortedIndexes.erase(unsortedIndexes.begin() + ind);
			updateIndex(whereInsertMe, whereImFrom, sortedIndexes, range);
			updateIndex(whereInsertMe, whereImFrom, unsortedIndexes, range);
			sortedIndexes.insert(std::lower_bound(sortedIndexes.begin(), sortedIndexes.end(), whereInsertMe), whereInsertMe);
		}
		duoJacobsthalNbr = getDuoJacobsthalNbr(false);
		indexMax = getMultipleOfTwo(false) - 1;
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

void  PmergeMe::vec_insertions(int range){

  std::vector<int> main_chain;
  std::vector<int> pending_chain;

  fill_chains(main_chain, pending_chain, range);

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
  vec_insertions(range);

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
