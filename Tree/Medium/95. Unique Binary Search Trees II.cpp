/* LeetCode 95. Unique Binary Search Trees II
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * Input: 3
 * Output:
 * [
 *   [1,null,3,2],
 *   [3,2,null,1],
 *   [3,1,null,null,2],
 *   [2,1,3],
 *   [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return vector<TreeNode*>();
		return generateTree(1, n);
	}
    
private:
        // 对 from...to 构造出 UBST，返回所有 UBST
	vector<TreeNode*> generateTree(int from, int to) {
		vector<TreeNode*> ret;
		if (from > to)
			ret.push_back(nullptr);
		else if (from == to)
			ret.push_back(new TreeNode(from));
		else {
			// 以 i 为根节点
			for (int i = from; i <= to; ++i) {
				// 递归求解所有可能的左子树
				vector<TreeNode*> left_subtree = generateTree(from, i - 1);
				// 递归求解所有可能的右子树
				vector<TreeNode*> right_subtree = generateTree(i + 1, to);

				// 左子树x右子树，在加上根节点，构成一个 from...to 的UBST
				// 这里用两层循环实现了左右子树的组合。可见，与 96. Unique Binary Search Trees 的思想是相通的。
				for (int j = 0; j < left_subtree.size(); ++j) {
					for (int k = 0; k < right_subtree.size(); ++k) {
						TreeNode* root = new TreeNode(i);
						root->left = left_subtree[j];
						root->right = right_subtree[k];
						ret.push_back(root);
					}
				}
			}
		}
		return ret;
	}
};
