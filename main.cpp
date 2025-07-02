#include "include/CInConserve.hpp"
#include <memory>
int main() {
    // Create a Bird object
    Falconiformes eagle("Eagle", "Golden Eagle", "Aquila chrysaetos", 5, 2.3, "Mountains", true, NOT_ENDANGERED);
    
    // Display bird information
    eagle.displayInfo();
    
    // Modify some attributes
    eagle.setAge(6);
    eagle.setendangeredStatus(VULNERABLE);
    
    // Display updated information
    std::cout << "\nUpdated Information:\n";
    eagle.displayInfo();
    
    return 0;
}