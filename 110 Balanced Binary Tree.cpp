/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Checks an entire tree recursively to examine if it is balanced, all subtrees must be balanced as well as root.
    bool isBalanced(TreeNode* root) {
        return lowestDepthFirstSearch(root) >= 0; // Negative depth means we must not be balanced
    }

    // Returns the height as a positive integer if balanced.
    // If not balanced, returns INT_MIN.
    int lowestDepthFirstSearch(TreeNode* root){
        // Guard case
        if (root == nullptr) {
            return 0;
        }

        // Left height recursion
        int left = lowestDepthFirstSearch(root->left);
        if (left == INT_MIN){ // Imbalanced child tree
            return INT_MIN; // Just terminate the entire sequence
        } // Note, this cascades upward and resolves every function call

        // Right height recursion, second verse same as the first
        int right = lowestDepthFirstSearch(root->right);
        if (right == INT_MIN){
            return INT_MIN;
        }

        if (abs(left - right) > 1){ // If the current node is imbalanced
            return INT_MIN;
        }
        // If the code reaches here, the tree rooted where it was called and its subtrees are height balanced
        return (max(left, right) + 1); // Height
    }
};