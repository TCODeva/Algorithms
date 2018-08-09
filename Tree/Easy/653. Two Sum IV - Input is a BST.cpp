/* LeetCode 653. Two Sum IV - Input is a BST
 * Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * Input: 
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * Example 2:
 * Input: 
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> list;
        inorderTreverse(root, list);
        int tail = list.size()-1, head = 0;
        while (head < tail) {
            if (list[head] + list[tail] == k) 
                return true;
            else if (list[head] + list[tail] < k) 
                head++;
            else 
                tail--;
        }
        return false;
    }
    
private:
    void inorderTreverse(TreeNode* root, vector<int>& list) {
        if (!root) return;
        inorderTreverse(root->left, list);
        list.push_back(root->val);
        inorderTreverse(root->right, list);
    }
};
