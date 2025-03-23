class Solution {
public:
    bool isAnagram(string s, string t) { // Please never name your strings "s" and "t" in proper code, provide them descriptive names
        // Time O(2(s+t)), Space O(s)
        // create a data structure to store the character and its count
        map<char, int> characterCounter;
        // iterate through the list "s", incrementing each
        for (const auto &character : s){
            auto result = characterCounter.emplace(character, 1); // Creates the pair if it doesnt exists
            if (!result.second) { // emplace.second is a bool indicating if an insertion happened
                result.first->second++; // emplace.first is the iterator, so we are accessing our int and incrementing it
            }
        }
        // iterate through the list "t", decrementing each letter
        for (const auto &character : t){
            auto result = characterCounter.emplace(character, 1); // Creates the pair if it doesnt exists
            if (!result.second) { // no insertion case
                result.first->second--; // emplace.first is the iterator, so we are accessing our int and incrementing it
            } else { // we just added a new element from string t, it cannot be an annagram
                return false;
            }
        }
        // check that all items in the data structure are 0, if a nonzero is found, return false
        for (const auto eachPair : characterCounter){
            if (eachPair.second != 0){
                return false;
            }
        }
        // implicit else to return true
        return true;
    }
};