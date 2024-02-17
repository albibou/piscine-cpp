/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:05:57 by atardif           #+#    #+#             */
/*   Updated: 2023/12/30 17:04:11 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void){

    std::cout << "Constructors called for \"good\" Animals : " << std::endl << std::endl;
    const Animal    *meta = new Animal();
    const Animal    *j = new Dog();
    const Animal    *i = new Cat();

    std::cout << std::endl;

    std::cout << "Get type of j : " << j->getType() << " " << std::endl;
    std::cout << "Get type of i : " << i->getType() << " " << std::endl << std::endl;
    std::cout << "i makes sound : "; 
    i->makeSound();
    std::cout << "j makes sound : ";
    j->makeSound();
    std::cout << "meta makes sound : ";
    meta->makeSound();

    std::cout << std::endl << "Constructors called for \"wrong\" Animals : " << std::endl <<std::endl;

    const WrongAnimal   *beta = new WrongAnimal();
    const WrongAnimal   *x = new    WrongCat();
    const WrongCat      *y = new    WrongCat();

    std::cout << std::endl;
    
    std::cout << "Get type of beta : " << beta->getType() << " " << std::endl;
    std::cout << "Get type of x : " << x->getType() << " " << std::endl;
    std::cout << "Get type of y : " << y->getType() << " " << std::endl << std::endl;
    std::cout << "beta makes sound : ";
    beta->makeSound();
    std::cout << "x makes sound : ";
    x->makeSound();
    std::cout << "y makes sound : ";
    y->makeSound();


    std::cout << std::endl << "Destructors : " << std::endl << std::endl;

    delete meta;
    delete j;
    delete i;
    delete beta;
    delete x;
    delete y;
    return 0;
}
