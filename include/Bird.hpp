#ifndef BIRD_HPP
#define BIRD_HPP

#include <string>
#include <iostream>
#include <iomanip>

enum EndangeredStatus { // levels of endangered status
    NOT_ENDANGERED, // 0
    VULNERABLE, // 1
    ENDANGERED, // 2
    CRITICALLY_ENDANGERED // 3
};

class Bird {
private: // Bird attributes
    std::string name;
    std::string popularName;
    std::string scientificName;
    int age;
    float wingspan;
    std::string naturalHabitat;
    bool isMigratory;
    EndangeredStatus endangeredStatus;

public:
    Bird(const std::string& name, const std::string& popularName, const std::string& scientificName, 
         int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus); // constructor

    // Getters
    std::string getName() const;
    std::string getPopularName() const;
    std::string getScientificName() const;
    int getAge() const;
    float getWingspan() const;
    std::string getNaturalHabitat() const;
    bool getIsMigratory() const;
    EndangeredStatus getendangeredStatus() const;

    // Setters
    void setName(const std::string& newName);
    void setPopularName(const std::string& newPopularName);
    void setScientificName(const std::string& newScientificName);
    void setAge(int newAge);
    void setWingspan(float newWingspan);
    void setNaturalHabitat(const std::string& newNaturalHabitat);
    void setIsMigratory(bool newIsMigratory);
    void setendangeredStatus(EndangeredStatus newendangeredStatus);

    // Virtual methods
    virtual std::string getBirdType() const; // returns the type of bird which depends on the derived class
    virtual void displayInfo() const;
    virtual ~Bird(); // virtual destructor
};
// Derived classes stored in separate files
// Anseriformes
// Falconiformes
// Galliformes
// Passeriformes
// Psittaciformes

#endif // BIRD_HPP