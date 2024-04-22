/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:44:46 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:44:47 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

static Base  *generate(void){

  Base  *ptr;
  int num = rand() % 3;

  switch (num){

    case 1:
      return (std::cout << "A generated" << std::endl, ptr = new A);
    case 2:
      return (std::cout << "B generated" << std::endl, ptr = new B);
    default:
      return (std::cout << "C generated" << std::endl, ptr = new C);
  }
  return NULL;
}

static void identify(Base *p){

  if (!dynamic_cast<A *>(p)){
    if (!dynamic_cast<B *>(p)){
      if (!dynamic_cast<C *>(p)){
        return (void)(std::cout << "Object is of unknown type" << std::endl);
      }
      return (void)(std::cout << "Object is of \"C\" type" << std::endl);
    }
    return (void)(std::cout << "Object is of \"B\" type" << std::endl);
  }
  return (void)(std::cout << "Object is of \"A\" type" << std::endl);
}

static void identify(Base &p){

  Base test;
  try {
    test = dynamic_cast<A &>(p);
    std::cout << "Object is of \"A\" type" << std::endl;
  }
  catch (const std::exception & e){
    try {
      test = dynamic_cast<B &>(p);
      std::cout << "Object is of \"B\" type" << std::endl;
    }
    catch (const std::exception & e){
      std::cout << "Object is of \"C\" type" << std::endl;
    }
  }
}

int main(void){

  std::cout << "Let's generate Objects" << std::endl;

  Base * p1 = generate();
  Base * p2 = generate();
  Base * p3 = generate();
  Base * p4 = generate();
  Base * p5 = generate();
  Base * p6 = generate();

  std::cout << std::endl << "Let's try to identify objects using pointers" << std::endl;

  identify(p1);
  identify(p2);
  identify(p3);
  identify(p4);
  identify(p5);
  identify(p6);
  identify(NULL);

  Base & r1 = *p1;
  Base & r2 = *p2;
  Base & r3 = *p3;
  Base & r4 = *p4;
  Base & r5 = *p5;
  Base & r6 = *p6;

  std::cout << std::endl << "Let's try to identify objects using references" << std::endl;

  identify(r1);
  identify(r2);
  identify(r3);
  identify(r4);
  identify(r5);
  identify(r6);

  delete p1;
  delete p2;
  delete p3;
  delete p4;
  delete p5;
  delete p6;

  return (0);
}
