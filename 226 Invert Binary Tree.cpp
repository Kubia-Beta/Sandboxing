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
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root); // Start the recursive inversion
        return root;
    }

    // Depth First Search (DFS) until we reach a leaf node
    void invertTreeHelper(TreeNode* root){
        // Null guard case
        if (root == nullptr){
            return;
        }
        // Leaf guard case
        if (root->left == nullptr && root->right == nullptr) {
            return; // No action needs to be taken and no calls need to be made on a leaf node
        }

        // Internal node and root nodes reach here to recurse
        invertTreeHelper(root->left);
        invertTreeHelper(root->right);
        // Once we have exhausted all traversal down and we are not on a leaf node
        // create a temporary pointer and swap the left and right pointers
        auto tempPtr = root->left;
        root->left = root->right;
        root->right = tempPtr;
        // The subtree is now inverted.
        return; // Move to the parent node
    }
    
};