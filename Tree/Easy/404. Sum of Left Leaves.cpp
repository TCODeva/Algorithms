/* LeetCode 404. Sum of Left Leaves
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, 0);
    }
    
private:
    int sum = 0;
    
    int helper(TreeNode* root, int flag) {
        if (!root) return 0;
        if (!root->left && !root->right && flag) sum += root->val;
        helper(root->left, 1);
        helper(root->right, 0);
        return sum;
    }
};
