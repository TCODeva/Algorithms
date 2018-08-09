/* LeetCode 637. Average of Levels in Binary Tree
 * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 * Example 1:
 * Input:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
 * Note:
 * The range of node's value is in the range of 32-bit signed integer.
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
 
Depth-first Search:

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> count;
        vector<double> res;
        helper(root, 0, count, res);
        for (int i = 0; i < res.size(); i++)
            res[i] = res[i] / count[i];
        return res;
    }
    
private:
    void helper(TreeNode* root, int level, vector<double>& count, vector<double>& sum) {
        if (root == NULL) return;
        if (level >= sum.size()) {
            sum.push_back(root->val);
            count.push_back(1);
        } else {
            sum[level] += root->val;
            count[level]++;
        }
        helper(root->left, level + 1, count, sum);
        helper(root->right, level + 1, count, sum);
    }
};

Breadth-first Search:

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            double temp = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                temp += t->val;
            }
            res.push_back(temp / n);
            
        }
        return res;
    }
};
