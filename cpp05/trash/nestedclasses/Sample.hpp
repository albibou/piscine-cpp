#ifndef SAMPLE_H
# define SAMPLE_H

#include <string>
#include <iostream>

class   Sample{

    public :

        Sample(){std::cout << "Sample Constructed" << std::endl;}
        ~Sample(){std::cout << "Sample Destructed" << std::endl;}
        class   Test{

            public :

            Test(){std::cout << "Test Constructed" << std::endl;}
            ~Test(){std::cout << "Test Destructed" << std::endl;}
            
            private :

        };

    private :


};






#endif
