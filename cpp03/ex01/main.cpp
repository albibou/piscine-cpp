#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap    clap("Abott");
    ClapTrap    clap2("Newman");
    ClapTrap    clap3(clap2);

    clap.attack("Newman");
    clap3.takeDamage(0);
    clap.beRepaired(1000);

    ScavTrap    scav("Williams");
    ScavTrap    scav2("Romalotti");
    ScavTrap    scav3(scav2);

    scav.attack("Romalotti");
    scav3.takeDamage(20);
    scav3.beRepaired(21);
    for(int i = 0; i < 51; i++)
        scav2.guardGate();
    return (0);
}
