#include "Span.hpp"

int generate_random_number(void){

  int number = std::rand() % INT_MAX;
  return (number);
}

void test_with_vector(void){

  std::cout << std::endl << "Test 5 : We're now going to fill a vector with 15000 numbers and fill a Span with it" << std::endl;

  std::vector<int> vector_test(15000);
  std::generate(vector_test.begin(), vector_test.end(), generate_random_number);

  Span  span2(15000);
  span2.addManyNumbers(vector_test.begin(), vector_test.end());

  try {
    std::cout << "We're outputing the content of the Span in a file for test purpose" << std::endl;
    std::ofstream file1("span2_content");
    if (!file1.fail()){
      file1 << span2;
      file1.close();
    }
  }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl << "Test 6 : Enough Numbers from vector initialisation" << std::endl;
  try{
        std::cout << SHORT_SPAN << span2.shortestSpan() << std::endl;
        std::cout << LONG_SPAN << span2.longestSpan() << std::endl;
      }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl << "Test 7 : adding number over capacity" << std::endl;

  try {
    span2.addNumber(42);
  }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }
  return;
}

void test_with_list(void){

  std::cout << std::endl << "Test 8 : We're now going to fill a list with 15000 numbers and fill a Span with it" << std::endl;

  std::list<int> list_test(15000);
  std::generate(list_test.begin(), list_test.end(), generate_random_number);

  Span  span3(15000);
  span3.addManyNumbers(list_test.begin(), list_test.end());

  try {
    std::cout << "We're outputing the content of the Span in a file for test purpose" << std::endl;
    std::ofstream file1("span3_content");
    if (!file1.fail()){
      file1 << span3;
      file1.close();
    }
  }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl << "Test 9 : Enough Numbers from list initialisation" << std::endl;
  try{
        std::cout << SHORT_SPAN << span3.shortestSpan() << std::endl;
        std::cout << LONG_SPAN << span3.longestSpan() << std::endl;
      }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }
  return ;
}

void test_members_functions(void){

  std::cout << "We're going to test methods on a Span containing few numbers : " << std::endl;

  Span span1(5);

  span1.addNumber(3);
  std::cout << std::endl << "Test 1 :  with less than two numbers" << std::endl;
  try{
    std::cout << SHORT_SPAN << span1.shortestSpan() << std::endl;
  }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }

  span1.addNumber(10);
  span1.addNumber(5);
  std::cout << std::endl << "Test 2 : with enough numbers" << std::endl;
  std::cout << "Span1 :" << std::endl << span1 << std::endl;
  try{
      std::cout << SHORT_SPAN << span1.shortestSpan() << std::endl;
      std::cout << LONG_SPAN << span1.longestSpan() << std::endl;
    }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }

  span1.addNumber(INT_MAX);
  span1.addNumber(INT_MIN);
  std::cout << std::endl << "Test 3 : with extreme values" << std::endl;
  std::cout << "Span1 :" << std::endl << span1 << std::endl;
  try{
      std::cout << SHORT_SPAN << span1.shortestSpan() << std::endl;
      std::cout << LONG_SPAN << span1.longestSpan() << std::endl;
    }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Test 4 : adding number over capacity" << std::endl;

  try {
    span1.addNumber(42);
  }
  catch (std::exception const & e){
    std::cerr << e.what() << std::endl;
  }
  return ;
}

int main(void){

  test_members_functions();
  test_with_vector();
  test_with_list();

  return (0);
}
