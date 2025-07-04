#ifndef FALCONIFORMES_HPP
#define FALCONIFORMES_HPP

#include <string>
#include "Bird.hpp"

class Falconiformes : public Bird {
public:
    Falconiformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                  int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus);
    std::string getBirdType() const override; // Bird type is overridden to Falconiformes
};


#endif // FALCONIFORMES_HPP