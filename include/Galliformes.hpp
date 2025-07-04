#ifndef GALLIFORMES_HPP
#define GALLIFORMES_HPP
#include "Bird.hpp"

class Galliformes : public Bird {
public:
    Galliformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus);
    std::string getBirdType() const override; // Bird type is overriden to Galliformes
};

#endif // GALLIFORMES_HPP