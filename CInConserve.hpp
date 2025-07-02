#include <string>
#include <iostream>
#include <iomanip>

enum EndangeredStatus {
    NOT_ENDANGERED, // 0
    VULNERABLE, // 1
    ENDANGERED, // 2
    CRITICALLY_ENDANGERED // 3
};

class Bird{
    private:
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
    int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : name(name), popularName(popularName), scientificName(scientificName), 
          age(age), wingspan(wingspan), naturalHabitat(naturalHabitat), 
          isMigratory(isMigratory), endangeredStatus(endangeredStatus) {} // Constructor
    
    // Getters
    std::string getName() const { return name; }
    std::string getPopularName() const { return popularName; }
    std::string getScientificName() const { return scientificName; }
    int getAge() const { return age; }
    float getWingspan() const { return wingspan; }
    std::string getNaturalHabitat() const { return naturalHabitat; }
    bool getIsMigratory() const { return isMigratory; }
    bool getendangeredStatus() const { return endangeredStatus; }

    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setPopularName(const std::string& newPopularName) { popularName = newPopularName; }
    void setScientificName(const std::string& newScientificName) { scientificName = newScientificName; }
    void setAge(int newAge) { age = newAge; }
    void setWingspan(float newWingspan) { wingspan = newWingspan; }
    void setNaturalHabitat(const std::string& newNaturalHabitat) { naturalHabitat = newNaturalHabitat; }
    void setIsMigratory(bool newIsMigratory) { isMigratory = newIsMigratory; }
    void setendangeredStatus(EndangeredStatus newendangeredStatus) { endangeredStatus = newendangeredStatus; }

    // Virtual methods to display bird informaion
    virtual std::string getBirdType() const { return "Generic Bird"; }
    virtual void displayInfo() const {
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
    virtual ~Bird() = default; // Virtual Destructor (proper cleanup when using polymorphism)

};

class Passeriformes : public Bird {
public:
    Passeriformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                  int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}
    
    std::string getBirdType() const override { return "Passeriformes (Small songbirds)"; }
};

class Anseriformes : public Bird {
public:
    Anseriformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                 int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}
    
    std::string getBirdType() const override { return "Anseriformes (Waterfowl)"; }
};

class Falconiformes : public Bird {
public:
    Falconiformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                  int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}
    
    std::string getBirdType() const override { return "Falconiformes (Birds of prey)"; }
};

class Cuculiformes : public Bird {
public:
    Cuculiformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                 int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}
    
    std::string getBirdType() const override { return "Cuculiformes (Cuckoos and allies)"; }
};

class Columbiformes : public Bird {
public:
    Columbiformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                  int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}
    
    std::string getBirdType() const override { return "Columbiformes (Doves and pigeons)"; }
};

class Charadriiformes : public Bird {
public:
    Charadriiformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                    int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}
    
    std::string getBirdType() const override { return "Charadriiformes (Shorebirds and seabirds)"; }
};

class Psittaciformes : public Bird {
public:
    Psittaciformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                   int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus)
        : Bird(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, endangeredStatus) {}
    
    std::string getBirdType() const override { return "Psittaciformes (Parrots and allies)"; }
};
