#ifndef SAMPLE_H
# define SAMPLE_H
 
#include <iostream>
#include <string>

class Aabstract{

    public :

        Aabstract(void);
        virtual ~Aabstract(void);

        virtual void    sayHello(void) = 0;
        void            sayGoodbye(void);
};

class Iinterface{

    public :

        Iinterface(void);
        virtual ~Iinterface(void);

        virtual void    sayCheers(void) = 0;
        virtual void    sayYes(void) = 0;
};

class Sample : public Aabstract, public Iinterface
{
   public:
 
      Sample(void);
      ~Sample(void);

      virtual void    sayCheers(void);
      virtual void    sayYes(void);
      virtual void    sayHello(void);
 
   private:
};
#endif // SAMPLE_H

