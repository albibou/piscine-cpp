#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void){

    const Animal    *meta = new Animal();
    const Animal    *j = new Dog();
    const Animal    *i = new Cat();
    const WrongAnimal   *beta = new WrongAnimal();
    const WrongAnimal   *x = new    WrongCat();


    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << beta->getType() << " " << std::endl;
    std::cout << x->getType() << " " << std::endl;
    beta->makeSound();
    x->makeSound();

    delete meta;
    delete j;
    delete i;
    delete beta;
    delete x;

    return 0;
}
