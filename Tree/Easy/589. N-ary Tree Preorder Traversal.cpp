/* LeetCode 589. N-ary Tree Preorder Traversal
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 *  
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * 
 *  
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> traversal;
        helper(root, traversal);
        return traversal;
    }
    
private:
    void helper(Node* root, vector<int>& traversal) {
        if (!root) return;
        traversal.push_back(root->val);
        for (Node* child : root->children)
            helper(child, traversal);
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* temp = stk.top();
            stk.pop();
            for (int i = temp->children.size() - 1; i >= 0; i--) 
                stk.push(temp->children[i]);
            res.push_back(temp->val);
        }
        return res;
    }
};
