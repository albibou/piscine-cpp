#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    clap("Abott");
    ClapTrap    clap2("Newman");

    clap.attack("Newman");
    clap2.takeDamage(0);


    clap.beRepaired(1000);
    for (int i = 0; i < 15; i++)
        clap.attack("Newman");
    return (0);
}
