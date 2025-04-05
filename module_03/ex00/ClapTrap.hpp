#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string const &name);
        ClapTrap(ClapTrap const& obj);
        ClapTrap& operator=(ClapTrap const& obj);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string const get_name() const;
        int get_health() const;
        void set_health(int health);
        int get_energy_points() const;
        void set_energy_points(int energy_points);
        int get_attack_damage() const;
        void set_attack_damage(int attack_damage);

    private:
        const std::string name;
        int health;
        int energy_points;
        int attack_damage;
};

#endif
