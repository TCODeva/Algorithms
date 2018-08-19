/* LeetCode 107. Binary Tree Level Order Traversal II
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* e = q.front();
                q.pop();
                if (e->left) q.push(e->left);
                if (e->right) q.push(e->right);
                level.push_back(e->val);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
