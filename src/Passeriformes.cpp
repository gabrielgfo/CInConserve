#include "../include/Passeriformes.hpp"
#include <string>

Passeriformes::Passeriformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                             int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
    : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}

std::string Passeriformes::getBirdType() const { return "Passeriformes (Small songbirds)"; }