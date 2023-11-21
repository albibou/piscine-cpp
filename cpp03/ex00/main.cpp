#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    clap("Robert");

    clap.attack("Roger");
    clap.takeDamage(5);
    clap.beRepaired(1000);
    for (int i = 0; i < 15; i++)
        clap.attack("Maurice");
    return (0);
}
