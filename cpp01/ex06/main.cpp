#include "Harl.hpp"

int main(int argc, char **argv){

    if (argc != 2)
    {
        std::cout << "Use as ./harl \"complaint\"" << std::endl;
        return (1);
    }

    Harl    harl;
    std::string str(argv[1]);

    harl.complain(str);
    return(0);
}
