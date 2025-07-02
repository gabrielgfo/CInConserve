#include "include/CInConserve.hpp"
#include <memory>
#include <vector>
#include <limits>

class BirdManager {
private:
    std::vector<std::unique_ptr<Bird>> birds;

public:
    void displayMenu() {
        std::cout << "\n========== Bird Conservation Management System ==========\n";
        std::cout << "1. Add a new bird\n";
        std::cout << "2. Display all birds\n";
        std::cout << "3. Edit a bird\n";
        std::cout << "4. Remove a bird\n";
        std::cout << "5. Find birds by endangered status\n";
        std::cout << "6. Exit\n";
        std::cout << "========================================================\n";
        std::cout << "Enter your choice (1-6): ";
    }

    int getBirdTypeChoice() {
        std::cout << "\nSelect bird type:\n";
        std::cout << "1. Passeriformes (Small songbirds)\n";
        std::cout << "2. Anseriformes (Waterfowl)\n";
        std::cout << "3. Falconiformes (Birds of Prey)\n";
        std::cout << "4. Galliformes (Landfowl)\n";
        std::cout << "5. Psittaciformes (Parrots)\n";
        std::cout << "Enter choice (1-5): ";
        
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(); // Clear the newline character
        return choice;
    }

    EndangeredStatus getEndangeredStatus() {
        std::cout << "\nSelect endangered status:\n";
        std::cout << "0. Not Endangered\n";
        std::cout << "1. Vulnerable\n";
        std::cout << "2. Endangered\n";
        std::cout << "3. Critically Endangered\n";
        std::cout << "Enter choice (0-3): ";
        
        int choice;
        while (!(std::cin >> choice) || choice < 0 || choice > 3) {
            std::cout << "Invalid input. Please enter a number between 0 and 3: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(); // Clear the newline character
        return static_cast<EndangeredStatus>(choice);
    }

    void addBird() {
        std::cout << "\n--- Adding New Bird ---\n";
        
        std::string name, popularName, scientificName, naturalHabitat;
        int age;
        float wingspan;
        bool isMigratory;
        
        std::cout << "Enter bird name: ";
        std::getline(std::cin, name);
        
        std::cout << "Enter popular name: ";
        std::getline(std::cin, popularName);
        
        std::cout << "Enter scientific name: ";
        std::getline(std::cin, scientificName);
        
        std::cout << "Enter age (years): ";
        while (!(std::cin >> age) || age < 0) {
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        std::cout << "Enter wingspan (meters): ";
        while (!(std::cin >> wingspan) || wingspan < 0) {
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(); // Clear the newline character
        
        std::cout << "Enter natural habitat: ";
        std::getline(std::cin, naturalHabitat);
        
        std::cout << "Is the bird migratory? (1 for Yes, 0 for No): ";
        int migratoryChoice;
        while (!(std::cin >> migratoryChoice) || (migratoryChoice != 0 && migratoryChoice != 1)) {
            std::cout << "Invalid input. Please enter 1 for Yes or 0 for No: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        isMigratory = (migratoryChoice == 1);
        std::cin.ignore(); // Clear the newline character
        
        EndangeredStatus status = getEndangeredStatus();
        int birdType = getBirdTypeChoice();
        
        std::unique_ptr<Bird> newBird;
        switch (birdType) {
            case 1:
                newBird = std::make_unique<Passeriformes>(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, status);
                break;
            case 2:
                newBird = std::make_unique<Anseriformes>(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, status);
                break;
            case 3:
                newBird = std::make_unique<Falconiformes>(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, status);
                break;
            case 4:
                newBird = std::make_unique<Galliformes>(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, status);
                break;
            case 5:
                newBird = std::make_unique<Psittaciformes>(name, popularName, scientificName, age, wingspan, naturalHabitat, isMigratory, status);
                break;
        }
        
        birds.push_back(std::move(newBird));
        std::cout << "\nBird added successfully!\n";
    }

    void displayAllBirds() {
        if (birds.empty()) {
            std::cout << "\nNo birds in the database.\n";
            return;
        }
        
        std::cout << "\n--- All Birds in Database ---\n";
        for (size_t i = 0; i < birds.size(); ++i) {
            std::cout << "\n--- Bird #" << (i + 1) << " ---\n";
            birds[i]->displayInfo();
            std::cout << "-------------------\n";
        }
    }

    void editBird() {
        if (birds.empty()) {
            std::cout << "\nNo birds in the database to edit.\n";
            return;
        }
        
        displayAllBirds();
        std::cout << "\nEnter the number of the bird to edit (1-" << birds.size() << "): ";
        
        int birdIndex;
        while (!(std::cin >> birdIndex) || birdIndex < 1 || birdIndex > static_cast<int>(birds.size())) {
            std::cout << "Invalid input. Please enter a number between 1 and " << birds.size() << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(); // Clear the newline character
        
        birdIndex--; // Convert to 0-based index
        
        std::cout << "\nWhat would you like to edit?\n";
        std::cout << "1. Name\n";
        std::cout << "2. Popular Name\n";
        std::cout << "3. Scientific Name\n";
        std::cout << "4. Age\n";
        std::cout << "5. Wingspan\n";
        std::cout << "6. Natural Habitat\n";
        std::cout << "7. Migratory Status\n";
        std::cout << "8. Endangered Status\n";
        std::cout << "Enter choice (1-8): ";
        
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 8) {
            std::cout << "Invalid input. Please enter a number between 1 and 8: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(); // Clear the newline character
        
        switch (choice) {
            case 1: {
                std::string newName;
                std::cout << "Enter new name: ";
                std::getline(std::cin, newName);
                birds[birdIndex]->setName(newName);
                break;
            }
            case 2: {
                std::string newPopularName;
                std::cout << "Enter new popular name: ";
                std::getline(std::cin, newPopularName);
                birds[birdIndex]->setPopularName(newPopularName);
                break;
            }
            case 3: {
                std::string newScientificName;
                std::cout << "Enter new scientific name: ";
                std::getline(std::cin, newScientificName);
                birds[birdIndex]->setScientificName(newScientificName);
                break;
            }
            case 4: {
                int newAge;
                std::cout << "Enter new age: ";
                while (!(std::cin >> newAge) || newAge < 0) {
                    std::cout << "Invalid input. Please enter a positive number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                birds[birdIndex]->setAge(newAge);
                break;
            }
            case 5: {
                float newWingspan;
                std::cout << "Enter new wingspan (meters): ";
                while (!(std::cin >> newWingspan) || newWingspan < 0) {
                    std::cout << "Invalid input. Please enter a positive number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                birds[birdIndex]->setWingspan(newWingspan);
                break;
            }
            case 6: {
                std::string newHabitat;
                std::cout << "Enter new natural habitat: ";
                std::getline(std::cin, newHabitat);
                birds[birdIndex]->setNaturalHabitat(newHabitat);
                break;
            }
            case 7: {
                int migratoryChoice;
                std::cout << "Is the bird migratory? (1 for Yes, 0 for No): ";
                while (!(std::cin >> migratoryChoice) || (migratoryChoice != 0 && migratoryChoice != 1)) {
                    std::cout << "Invalid input. Please enter 1 for Yes or 0 for No: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                birds[birdIndex]->setIsMigratory(migratoryChoice == 1);
                break;
            }
            case 8: {
                EndangeredStatus newStatus = getEndangeredStatus();
                birds[birdIndex]->setendangeredStatus(newStatus);
                break;
            }
        }
        
        std::cout << "\nBird updated successfully!\n";
    }

    void removeBird() {
        if (birds.empty()) {
            std::cout << "\nNo birds in the database to remove.\n";
            return;
        }
        
        displayAllBirds();
        std::cout << "\nEnter the number of the bird to remove (1-" << birds.size() << "): ";
        
        int birdIndex;
        while (!(std::cin >> birdIndex) || birdIndex < 1 || birdIndex > static_cast<int>(birds.size())) {
            std::cout << "Invalid input. Please enter a number between 1 and " << birds.size() << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        birdIndex--; // Convert to 0-based index
        
        std::cout << "\nAre you sure you want to remove this bird? (1 for Yes, 0 for No): ";
        int confirmation;
        while (!(std::cin >> confirmation) || (confirmation != 0 && confirmation != 1)) {
            std::cout << "Invalid input. Please enter 1 for Yes or 0 for No: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        if (confirmation == 1) {
            birds.erase(birds.begin() + birdIndex);
            std::cout << "\nBird removed successfully!\n";
        } else {
            std::cout << "\nRemoval cancelled.\n";
        }
    }

    void findByEndangeredStatus() {
        if (birds.empty()) {
            std::cout << "\nNo birds in the database.\n";
            return;
        }
        
        EndangeredStatus searchStatus = getEndangeredStatus();
        std::vector<Bird*> foundBirds;
        
        for (const auto& bird : birds) {
            if (bird->getendangeredStatus() == searchStatus) {
                foundBirds.push_back(bird.get());
            }
        }
        
        if (foundBirds.empty()) {
            std::cout << "\nNo birds found with the specified endangered status.\n";
        } else {
            std::cout << "\n--- Birds with Selected Endangered Status ---\n";
            for (size_t i = 0; i < foundBirds.size(); ++i) {
                std::cout << "\n--- Result #" << (i + 1) << " ---\n";
                foundBirds[i]->displayInfo();
                std::cout << "-------------------\n";
            }
        }
    }

    void run() {
        int choice;
        
        std::cout << "Welcome to the Bird Conservation Management System!\n";
        
        do {
            displayMenu();
            while (!(std::cin >> choice) || choice < 1 || choice > 6) {
                std::cout << "Invalid input. Please enter a number between 1 and 6: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(); // Clear the newline character
            
            switch (choice) {
                case 1:
                    addBird();
                    break;
                case 2:
                    displayAllBirds();
                    break;
                case 3:
                    editBird();
                    break;
                case 4:
                    removeBird();
                    break;
                case 5:
                    findByEndangeredStatus();
                    break;
                case 6:
                    std::cout << "\nThank you for using the Bird Conservation Management System!\n";
                    break;
            }
            
            if (choice != 6) {
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
            }
            
        } while (choice != 6);
    }
};

int main() {
    BirdManager manager;
    manager.run();
    return 0;
}