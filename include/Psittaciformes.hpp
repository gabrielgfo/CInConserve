#ifndef PSITTACIFORMES_HPP
#define PSITTACIFORMES_HPP

#include <string>
#include "Bird.hpp"

class Psittaciformes : public Bird {
public:
    Psittaciformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                   int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus);
    std::string getBirdType() const override;
};

#endif // PSITTACIFORMES_HPP