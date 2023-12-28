/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:08:52 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:08:53 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void){

    Aanimal  *test[10];
    //Aanimal test1;

    std::cout << std::endl << "We fill half of the array with Dogs objects and the other with Cat objects" << std::endl;
    for (int i = 0; i < 5; i++)
        test[i] = new Dog();
    for (int i = 5; i < 10; i++)
        test[i] = new Cat();

    std::cout << std::endl << "Let's check the types of each objects and their sound :" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Index n " << i << " ->type = " << test[i]->getType() << " : ";
        test[i]->makeSound();
    }

    std::cout << std::endl << "Let's declare a Dog object and fill its ideas :" << std::endl;

    Dog     Dog1;
    for (int i = 1; i < 51; i++)
        Dog1.fillIdea("Banana", i);
    for (int i = 51; i < 101; i++)
        Dog1.fillIdea("Mango", i);
    Dog1.displayIdeas();


    std::cout << std::endl << "Let's declare another Dog object with default ideas :" << std::endl;
    Dog     Dog2;
    Dog2.displayIdeas();

    std::cout << std::endl << "Let's call assignation operator, the ideas must now be identical to the first instance :" << std::endl;
    Dog2 = Dog1;
    Dog2.displayIdeas();
    

    std::cout << std::endl << "Let's try copy constructor (the ideas displayed must be the same that the first instance) : " << std::endl;
    {
    Dog Dog3(Dog1);
    Dog3.displayIdeas();
    }

    std::cout << std::endl << "Now that the new brain is destroyed, we must still have access to the brain of the first instance if the copy was deep :  " << std::endl;
    Dog1.displayIdeas();

    std::cout << std::endl << "Destructors called for the array of Animals : " << std::endl;
    for (int i = 0; i < 10; i++)
        delete test[i];

    std::cout << std::endl << "Destructors called for the other objects declared : " << std::endl;
    return 0;
}
