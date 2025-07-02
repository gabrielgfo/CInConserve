#include "CInConserve.hpp"

// Bird class implementations
Bird::Bird(const std::string& name, const std::string& popularName, const std::string& scientificName, 
           int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
    : name(name), popularName(popularName), scientificName(scientificName), 
      age(age), wingspan(wingspan), naturalHabitat(naturalHabitat), 
      isMigratory(isMigratory), endangeredStatus(endangeredStatus) {}

std::string Bird::getName() const { return name; }
std::string Bird::getPopularName() const { return popularName; }
std::string Bird::getScientificName() const { return scientificName; }
int Bird::getAge() const { return age; }
float Bird::getWingspan() const { return wingspan; }
std::string Bird::getNaturalHabitat() const { return naturalHabitat; }
bool Bird::getIsMigratory() const { return isMigratory; }
bool Bird::getendangeredStatus() const { return endangeredStatus; }

void Bird::setName(const std::string& newName) { name = newName; }
void Bird::setPopularName(const std::string& newPopularName) { popularName = newPopularName; }
void Bird::setScientificName(const std::string& newScientificName) { scientificName = newScientificName; }
void Bird::setAge(int newAge) { age = newAge; }
void Bird::setWingspan(float newWingspan) { wingspan = newWingspan; }
void Bird::setNaturalHabitat(const std::string& newNaturalHabitat) { naturalHabitat = newNaturalHabitat; }
void Bird::setIsMigratory(bool newIsMigratory) { isMigratory = newIsMigratory; }
void Bird::setendangeredStatus(EndangeredStatus newendangeredStatus) { endangeredStatus = newendangeredStatus; }

std::string Bird::getBirdType() const { return "Generic Bird"; }
void Bird::displayInfo() const {
    std::cout << "Type: " << getBirdType() << "\n"
              << "Name: " << name << "\n"
              << "Popular Name: " << popularName << "\n"
              << "Scientific Name: " << scientificName << "\n"
              << "Age: " << age << " years\n"
              << "Wingspan: " << wingspan << " meters\n"
              << "Natural Habitat: " << naturalHabitat << "\n"
              << "Migratory: " << (isMigratory ? "Yes" : "No") << "\n"
              << "Endangered Status: " << ((endangeredStatus == 0) ? "Not Endangered" : (endangeredStatus == 1)
              ? "Vulnerable" : (endangeredStatus == 2) ? "Endangered" : "Critically Endangered")  << "\n";
}
Bird::~Bird() = default;

// Derived class implementations
Passeriformes::Passeriformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                             int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
    : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}

std::string Passeriformes::getBirdType() const { return "Passeriformes (Small songbirds)"; }

// Repeat similar implementations for other derived classes...
// ...existing code...
