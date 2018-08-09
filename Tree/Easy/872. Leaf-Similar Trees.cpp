/* LeetCode 872. Leaf-Similar Trees
 * Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
 * 
 * 
 * 
 * Note:
 * 
 * Both of the given trees will have between 1 and 100 nodes.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        helper(root1, l1);
        helper(root2, l2);
        return l1 == l2;
    }
    
private:
    void helper(TreeNode* r, vector<int>& l) {
        if (r == NULL) return;
        if (r->left == NULL && r->right == NULL) l.push_back(r->val);
        helper(r->left, l);
        helper(r->right, l);
    }
};
