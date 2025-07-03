#include "../include/Galliformes.hpp"

Galliformes::Galliformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                         int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
    : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}

std::string Galliformes::getBirdType() const { return "Galliformes (Landfowl))"; }