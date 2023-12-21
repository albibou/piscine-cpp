/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:57 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:24:04 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

    std::cout << beta->getType() << " " << std::endl;
    std::cout << x->getType() << " " << std::endl;
    beta->makeSound();
    x->makeSound();

    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete beta;
    delete x;

    return 0;
}
