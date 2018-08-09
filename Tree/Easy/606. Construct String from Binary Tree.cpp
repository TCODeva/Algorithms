/* LeetCode 606. Construct String from Binary Tree
 * You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
 * 
 * The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
 * 
 * Example 1:
 * Input: Binary tree: [1,2,3,4]
 *        1
 *      /   \
 *     2     3
 *    /    
 *   4     
 * 
 * Output: "1(2(4))(3)"
 * 
 * Explanation: Originallay it needs to be "1(2(4)())(3()())", 
 * but you need to omit all the unnecessary empty parenthesis pairs. 
 * And it will be "1(2(4))(3)".
 * Example 2:
 * Input: Binary tree: [1,2,3,null,4]
 *        1
 *      /   \
 *     2     3
 *      \  
 *       4 
 * 
 * Output: "1(2()(4))(3)"
 * 
 * Explanation: Almost the same as the first example, 
 * except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = to_string(t->val);
        if (!t->left && !t->right) return s + "";
        if (!t->right) return s + "(" + tree2str(t->left) + ")";
        return s + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";   
    }
};

class Solution {
public:
    string tree2str(TreeNode* t) {
        string s = "";
        if(!t) return s;
        set<TreeNode*> visited_node;
        stack<TreeNode*> stack_node;
        stack_node.push(t);
        while (!stack_node.empty()) {
            t = stack_node.top();
            if (visited_node.find(t) == visited_node.end()) {
                s += "(" + to_string(t->val);
                visited_node.insert(t);
                if (t->right) stack_node.push(t->right);
                if (t->left) stack_node.push(t->left);
                if (!t->left && t->right) s += "()";
            } else {
                s += ")";
                stack_node.pop();
            }
        }
        //s.erase(s.begin() + 0);
        //s.erase(s.end() - 1);
        //return s;
        return s.substr(1, s.size() - 2);
    }
};
