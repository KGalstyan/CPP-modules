#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain& obj);
        Brain& operator=(const Brain& obj);
        std::string getIdea(int i);
        void setIdea(int i,const std::string idea);
        std::string ideas[100];
};

#endif