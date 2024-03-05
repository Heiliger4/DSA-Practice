#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map
    std::unordered_map<std::string, int> umap;

    // Inserting elements into the unordered_map
    umap["John"] = 28;
    umap["Alice"] = 30;
    umap["Bob"] = 25;
    umap["Diana"] = 22;

    // Accessing elements in the unordered_map
    std::cout << "Age of John: " << umap["John"] << std::endl;

    // Modifying elements in the unordered_map
    umap["Alice"] = 31;
    std::cout << "Updated age of Alice: " << umap["Alice"] << std::endl;

    // Checking if an element exists in the unordered_map
    if (umap.find("Bob") != umap.end()) {
        std::cout << "Bob's age is in the unordered_map" << std::endl;
    } else {
        std::cout << "Bob's age is not in the unordered_map" << std::endl;
    }

    // Iterating over all elements in the unordered_map
    for (const auto& pair : umap) {
        std::cout << pair.first << "'s age is " << pair.second << std::endl;
    }

    return 0;
}
