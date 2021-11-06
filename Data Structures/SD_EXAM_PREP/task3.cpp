#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
void compareRepeatingWords() {
    std::stringstream t1("In computing, a hash table (hash map) is a data structure used to implement an associative array, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the correct value can be found");
    std::stringstream t2("Ideally, the hash function will assign each key to a unique bucket, but this situation is rarely achievable in practice usually some keys will hash to the same bucket");
 
    std::unordered_map<std::string,int> map1;
    std::unordered_map<std::string,int> result;
 
    std::string word;
    while (t1 >> word) {
        map1[word] = 0;
    }
 
    int matchedWords = 0;
 
    while (t2 >> word) {
        if (!(map1.find(word) == map1.end())) {
            matchedWords++;
            result[word]++;
        }
    }
 
    std::cout << "We have " << matchedWords << " repeating words:" << std::endl;
    for (typename std::unordered_map<std::string, int>::iterator it = result.begin(); it != result.end(); ++it) {
        std::cout << it->first << " (" << result[it->first] << ")" << std::endl;
    }
}