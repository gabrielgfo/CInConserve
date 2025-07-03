#ifndef GALLIFORMES_HPP
#define GALLIFORMES_HPP

class Galliformes : public Bird {
public:
    Galliformes(const std::string& name, const std::string& popularName, const std::string& scientificName, 
                int age, float wingspan, const std::string& naturalHabitat, bool isMigratory, EndangeredStatus endangeredStatus);
    std::string getBirdType() const override;
};

#endif // GALLIFORMES_HPP