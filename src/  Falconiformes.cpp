#include "Falconiformes.hpp"

Falconiformes::Falconiformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                             int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
    : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}

std::string Falconiformes::getBirdType() const { return "Falconiformes (Birds of Prey)"; }