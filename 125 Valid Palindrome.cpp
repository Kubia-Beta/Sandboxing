class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; // Search pointers
        int right = s.size() - 1; // size() is 1 indexed
        // Move across the string with a two pointer solution similar to how we handle binary search
        while (left <= right){
            // A pointer skips on the condition (false == isalnum)
            if (false == isalnum(s[left])){ // If the item at the left position isnt a letter/number
                left++; // Move the pointer to the next item to read
                continue; // Start over to check for alphanumeric characters again
            }
            if (false == isalnum(s[right])){ // Note that the challenge specifies alphanumeric characters
                right--;
                continue;
            }
            // Every pointer movement, check if left = right
            if (tolower(s[left]) != tolower(s[right])){ // The characters do not match
                return false; // If ever left != right, return false
            }
            else {
                left++;
                right--;
            }
        }
        return true; // We can only access this by iterating through and comparing the entire string
    }
};