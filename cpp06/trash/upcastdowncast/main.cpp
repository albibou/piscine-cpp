#include <iostream>

class Parent{
};

class Child1 : public Parent {
};

class Child2 : public Parent {
};

int main(void){

  Child1 a;

  Parent *  b = &a;
  Parent *  c = (Parent *) &a;

  Parent *  d = &a;
//  Child1 *  e = d;
  Child2 *  f = (Child2 *) d;

  (void)a;
  (void)b;
  (void)c;
  (void)d;
  (void)f;

  return (0);
}
