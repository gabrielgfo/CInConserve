#include "Psittaciformes.hpp"
#include <string>

Psittaciformes::Psittaciformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                               int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
    : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}

std::string Psittaciformes::getBirdType() const { return "Psittaciformes (Parrots)"; }