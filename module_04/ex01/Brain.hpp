#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain& obj);
        Brain& operator=(const Brain& obj);
        ~Brain();
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
        std::string ideas[100];
};

#endif