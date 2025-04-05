#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt1("DiamondOne");
    dt1.whoAmI();
    dt1.attack("Enemy");

    DiamondTrap dt2(dt1);
    dt2.whoAmI();

    DiamondTrap dt3("Temporary");
    dt3 = dt1;
    dt3.whoAmI();

    std::cout << "DiamondOne - Health: " << dt1.get_health() << ", Energy: " << dt1.get_energy_points() << ", Attack Damage: " << dt1.get_attack_damage() << "\n";
    std::cout << "Clone (dt2) - Health: " << dt2.get_health() << ", Energy: " << dt2.get_energy_points() << ", Attack Damage: " << dt2.get_attack_damage() << "\n";
    std::cout << "Copy (dt3) - Health: " << dt3.get_health() << ", Energy: " << dt3.get_energy_points() << ", Attack Damage: " << dt3.get_attack_damage() << "\n";

    return 0;
}


