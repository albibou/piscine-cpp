#include "MutantStack.hpp"

void  vector_tests(void){

  std::cout << std::endl << "Tests on a vector" << std::endl;

  std::vector<int> vector_test;

  vector_test.push_back(6);
  vector_test.push_back(12);
  vector_test.push_back(-1000);
  vector_test.push_back(42);
  vector_test.push_back(0);
  vector_test.push_back(100);

  std::cout << std::endl << "Test 1 : now that we've added values, let's call size method" << std::endl;
  std::cout << "vector_test.size() = " << vector_test.size() << std::endl;

  std::cout << std::endl << "Test 2 : Let's see top element of vector " << std::endl;
  std::cout << "vector_test.back() = " << vector_test.back() << std::endl;

  std::cout << std::endl << "Test 3 : Let's see top element of vector after pop_back() " << std::endl;
  vector_test.pop_back();
  std::cout << "vector_test.back() = " << vector_test.back() << std::endl;

  std::cout << std::endl << "Test 4 : We're now going to use iterator to print content of vector" << std::endl;

  for (std::vector<int>::iterator it = vector_test.begin(); it != vector_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 5 : We're now going to use reverse_iterator to print content of vector backward" << std::endl;

  for (std::vector<int>::reverse_iterator it = vector_test.rbegin(); it != vector_test.rend(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 6 : Let's use iterators to swap values in our vector and reverse it in place " << std::endl;

  std::vector<int>::iterator vec_it_swap = vector_test.begin();
  std::vector<int>::reverse_iterator vec_rit_swap = vector_test.rbegin();

  for (size_t i = 0; i < vector_test.size() / 2; vec_it_swap++, vec_rit_swap++, i++){
    int tmp = *vec_rit_swap;
    *vec_rit_swap = *vec_it_swap;
    *vec_it_swap = tmp;
  }

  for (std::vector<int>::iterator it = vector_test.begin(); it != vector_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 7: Let's use iterators to modify values with other" << std::endl;

  std::srand(std::time(0));
  for (std::vector<int>::iterator it = vector_test.begin(); it != vector_test.end(); it++)
    *it = std::rand();

  for (std::vector<int>::iterator it = vector_test.begin(); it != vector_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 8: Let's run some stl algorithms on our vector" << std::endl;

  std::cout << std::endl << "std::sort :" << std::endl;
  std::sort(vector_test.begin(), vector_test.end());

  for (std::vector<int>::iterator it = vector_test.begin(); it != vector_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "std::reverse :" << std::endl;
  std::reverse(vector_test.begin(), vector_test.end());

  for (std::vector<int>::iterator it = vector_test.begin(); it != vector_test.end(); it++)
    std::cout << *it << std::endl;

  return ;
}

void  deque_tests(){

  std::cout << std::endl << "Tests on a deque, since that by default, stack containers are deque wrapped in a container adaptor" << std::endl;

  std::deque<int> deque_test;

  deque_test.push_back(6);
  deque_test.push_back(12);
  deque_test.push_back(-1000);
  deque_test.push_back(42);
  deque_test.push_back(0);
  deque_test.push_back(100);

  std::cout << std::endl << "Test 1 : now that we've added values, let's call size method" << std::endl;
  std::cout << "deque_test.size() = " << deque_test.size() << std::endl;

  std::cout << std::endl << "Test 2 : Let's see top element of deque " << std::endl;
  std::cout << "deque_test.back() = " << deque_test.back() << std::endl;

  std::cout << std::endl << "Test 3 : Let's see top element of deque after pop_back() " << std::endl;
  deque_test.pop_back();
  std::cout << "deque_test.back() = " << deque_test.back() << std::endl;

  std::cout << std::endl << "Test 4 : We're now going to use iterator to print content of deque" << std::endl;

  for (std::deque<int>::iterator it = deque_test.begin(); it != deque_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 5 : We're now going to use reverse_iterator to print content of deque backward" << std::endl;

  for (std::deque<int>::reverse_iterator it = deque_test.rbegin(); it != deque_test.rend(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 6 : Let's use iterators to swap values in our deque and reverse it in place " << std::endl;

  std::deque<int>::iterator deq_it_swap = deque_test.begin();
  std::deque<int>::reverse_iterator deq_rit_swap = deque_test.rbegin();

  for (size_t i = 0; i < deque_test.size() / 2; deq_it_swap++, deq_rit_swap++, i++){
    int tmp = *deq_rit_swap;
    *deq_rit_swap = *deq_it_swap;
    *deq_it_swap = tmp;
  }

  for (std::deque<int>::iterator it = deque_test.begin(); it != deque_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 7: Let's use iterators to modify values with other" << std::endl;

  std::srand(std::time(0));
  for (std::deque<int>::iterator it = deque_test.begin(); it != deque_test.end(); it++)
    *it = std::rand();

  for (std::deque<int>::iterator it = deque_test.begin(); it != deque_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 8: Let's run some stl algorithms on our deque" << std::endl;

  std::cout << std::endl << "std::sort :" << std::endl;
  std::sort(deque_test.begin(), deque_test.end());

  for (std::deque<int>::iterator it = deque_test.begin(); it != deque_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "std::reverse :" << std::endl;
  std::reverse(deque_test.begin(), deque_test.end());

  for (std::deque<int>::iterator it = deque_test.begin(); it != deque_test.end(); it++)
    std::cout << *it << std::endl;
  return ;
}

void  mutantStack_tests(void){

  std::cout << std::endl << "Tests on our MutantStack" << std::endl;

  MutantStack<int> mstack_test;

  mstack_test.push(6);
  mstack_test.push(12);
  mstack_test.push(-1000);
  mstack_test.push(42);
  mstack_test.push(0);
  mstack_test.push(100);

  std::cout << std::endl << "Test 1 : now that we've added values, let's call size method" << std::endl;
  std::cout << "mstack_test.size() = " << mstack_test.size() << std::endl;

  std::cout << std::endl << "Test 2 : Let's see top element of MutantStack " << std::endl;
  std::cout << "mstack_test.top() = " << mstack_test.top() << std::endl;

  std::cout << std::endl << "Test 3 : Let's see top element of MutantStack after pop_back() " << std::endl;
  mstack_test.pop();
  std::cout << "mstack_test.top() = " << mstack_test.top() << std::endl;

  std::cout << std::endl << "Test 4 : We're now going to use iterator to print content of MutantStack" << std::endl;

  for (MutantStack<int>::iterator it = mstack_test.begin(); it != mstack_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 5 : We're now going to use reverse_iterator to print content of MutantStack backward" << std::endl;

  for (MutantStack<int>::reverse_iterator it = mstack_test.rbegin(); it != mstack_test.rend(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 6 : Let's use iterators to swap values in our mutantStack and reverse it in place " << std::endl;

  MutantStack<int>::iterator mut_it_swap = mstack_test.begin();
  MutantStack<int>::reverse_iterator mut_rit_swap = mstack_test.rbegin();

  for (size_t i = 0; i < mstack_test.size() / 2; mut_it_swap++, mut_rit_swap++, i++){
    int tmp = *mut_rit_swap;
    *mut_rit_swap = *mut_it_swap;
    *mut_it_swap = tmp;
  }

  for (MutantStack<int>::iterator it = mstack_test.begin(); it != mstack_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 7: Let's use iterators to modify values with other" << std::endl;

  std::srand(std::time(0));
  for (MutantStack<int>::iterator it = mstack_test.begin(); it != mstack_test.end(); it++)
    *it = std::rand();

  for (MutantStack<int>::iterator it = mstack_test.begin(); it != mstack_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "Test 8: Let's run some stl algorithms on our mutant stack" << std::endl;

  std::cout << std::endl << "std::sort :" << std::endl;
  std::sort(mstack_test.begin(), mstack_test.end());

  for (MutantStack<int>::iterator it = mstack_test.begin(); it != mstack_test.end(); it++)
    std::cout << *it << std::endl;

  std::cout << std::endl << "std::reverse :" << std::endl;
  std::reverse(mstack_test.begin(), mstack_test.end());

  for (MutantStack<int>::iterator it = mstack_test.begin(); it != mstack_test.end(); it++)
    std::cout << *it << std::endl;
  return ;
}

int main(void){

  std::cout << "To demonstrate that our MutantStack is iterable, we are going to";
  std::cout << " operate on a vector and deque filled with the same values that our future MutantStack";
  std::cout << " and compare results : " << std::endl;

  vector_tests();
  deque_tests();
  mutantStack_tests();
  
  return (0);
}
