#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Create a hash map
    unordered_map<string, int> hashMap;

    // Inserting elements into the hash map
    hashMap["John"] = 28;
    hashMap["Alice"] = 30;
    hashMap["Bob"] = 25;
    hashMap["Diana"] = 22;

    // Accessing elements in the hash map
    cout << "Age of John: " << hashMap["John"] << endl;

    // Modifying elements in the hash map
    hashMap["Alice"] = 31;
    cout << "Updated age of Alice: " << hashMap["Alice"] << endl;

    // Checking if an element exists in the hash map
    if (hashMap.find("Bob") != hashMap.end()) {
        cout << "Bob's age is in the hash map" << endl;
    } else {
        cout << "Bob's age is not in the hash map" << endl;
    }

    // Iterating over all elements in the hash map
    for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
        cout << it->first << "'s age is " << it->second << endl;
    }

    return 0;
}
