#include "Sample.hpp"
#include "Sub.hpp"

int main(void){

    Sub *test1 = new Sub();
    Sample *test2 = new Sub();

    test1->greet("You");
    test2->greet("You");

    test1->ungreet("You");
    test2->ungreet("You");

    return (0);
}
