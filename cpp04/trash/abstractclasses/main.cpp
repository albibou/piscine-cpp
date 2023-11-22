#include "Sample.hpp"

int main(void){

    Sample  *test = new Sample();

    test->sayHello();
    test->sayCheers();
    test->sayYes();
    test->sayGoodbye();

    delete test;
    return (0);
}
