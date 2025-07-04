#ifndef PASSERIFORMES_HPP
#define PASSERIFORMES_HPP

#include <string>
#include "Bird.hpp"

class Passeriformes : public Bird {
public:
    Passeriformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                  int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus);
    std::string getBirdType() const override; // Bird type is overriden to Passeriformes
};

#endif // PASSERIFORMES_HPP