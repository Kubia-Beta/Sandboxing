class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //lookbehind algorithm
        int unique = 1; // unique element tracker, element 0 must be unique
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){ // If we find a new unique element (lookbehind)
                nums[unique] = nums[i]; // Move the new unique element
                unique++; // update to our next unique element position
            }
        }
        return unique; // Return the number of unique numbers
    }
};