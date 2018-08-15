/* LeetCode 538. Convert BST to Greater Tree
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 * 
 * Example:
 * 
 * Input: The root of a Binary Search Tree like this:
 *               5
 *             /   \
 *            2     13
 * 
 * Output: The root of a Greater Tree like this:
 *              18
 *             /   \
 *           20     13
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

//reverse in-order traversal:

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }

private:
    int sum = 0;
};

//Stack:

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        stack<TreeNode*> stack;

        while (!stack.empty() || node) {
            /* push all nodes up to (and including) this subtree's maximum on
             * the stack. */
            while (node) {
                stack.push(node);
                node = node->right;
            }

            node = stack.top();
            stack.pop();
            sum += node->val;
            node->val = sum;

            /* all nodes with values between the current and its parent lie in
             * the left subtree. */
            node = node->left;
        }

        return root;
    }
};
