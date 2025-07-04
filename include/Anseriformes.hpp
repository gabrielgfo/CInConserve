#ifndef ANSERIFORMES_HPP
#define ANSERIFORMES_HPP

#include <string>
#include "Bird.hpp"

class Anseriformes : public Bird {
public:
    Anseriformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                 int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus);
    std::string getBirdType() const override; // Bird type is overriden to Anseriformes
};

#endif // ANSERIFORMES_HPP