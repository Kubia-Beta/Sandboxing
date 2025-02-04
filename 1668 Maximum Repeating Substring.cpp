class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int solution = 0;
        string repeatedWord = word;
        while (sequence.find(repeatedWord) != string::npos) { //while we still have characters in the string left
            solution++; // increment the solution count
            repeatedWord = repeatedWord + word; // Build the word string up
        }
        return solution;
    }
};