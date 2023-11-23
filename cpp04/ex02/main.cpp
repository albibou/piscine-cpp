#include "Aanimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void){

    Aanimal  *test[10];
    Cat     *test1 = new Cat();

    for (int i = 0; i < 5; i++)
        test[i] = new Dog();
    for (int i = 5; i < 10; i++)
        test[i] = new Cat();

    for (int i = 0; i < 10; i++)
        test[i]->makeSound();

    for (int i = 1; i < 51; i++)
        test1->fillIdea("Banana", i);
    for (int i = 51; i < 101; i++)
        test1->fillIdea("Mango", i);

    test1->displayIdeas();

    for (int i = 0; i < 10; i++)
        delete test[i];

    return 0;
}
