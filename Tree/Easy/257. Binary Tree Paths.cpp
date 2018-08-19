/* LeetCode 257. Binary Tree Paths
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Input:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, "", res);
        return res;
    }
    
private:
    void helper(TreeNode* root, string s, vector<string>& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(s + to_string(root->val));
            return;
        }
        helper(root->left, s + to_string(root->val) + "->" , res);
        helper(root->right, s + to_string(root->val) + "->", res);
    }
};
