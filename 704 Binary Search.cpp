class Solution {
public:
    int search(vector<int>& nums, int target) { // Basic binary search
        int low = 0;
        int high = nums.size();
        // Consider that any data structure can be turned into a BST if it is sorted
        // A BST is a doubly linked list with an algorithm, nothing more
        while (low <= high){
            int mid = (low + high) / 2;
            if (mid >= nums.size()){ // guard case for when there is one element
                low, mid, high = 0;
            }
            else if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                low = mid +1;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
        }
        return -1;
    }
};