class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {}; // Vector to hold our result
        // does a + b = result?
        // weird: sort vector, then check mod%2 for binary search step
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int targetValue = target - nums[i]; // Target value to match in vector
            bool searchExists = binary_search(nums.begin(), nums.end(), targetValue); // Quickly check if our desired value exists
            if (searchExists == true) { // If it exists, find its position
                //int a = distance(nums.begin(), find(nums.begin(), nums.end(), ))
                int b = distance(nums.begin(), find(nums.begin(), nums.end(), targetValue));
                if (b != i){
                result.push_back(i);
                result.push_back(b);
                return result;
                }
            }
        }
        return result; // No solution was found
    }
};