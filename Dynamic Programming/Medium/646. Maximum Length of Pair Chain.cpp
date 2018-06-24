/* LeetCode 646. Maximum Length of Pair Chain
 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
 * 
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
 * 
 * Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
 * 
 * Example 1:
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * Note:
 * The number of given pairs will be in the range [1, 1000].
 */
 
Greedy:

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = 0, end = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto pair : pairs) {
            if (pair[0] > end) {
                ++len;
                end = pair[1];
            }
        }
        return len;
    }
};

DP:

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int n = pairs.size();
        vector<int> dp(n,1);
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (pairs[i][1] < pairs[j][0])
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }

        int len = 0;
        for (int i = 0; i < dp.size(); i++) 
            if (dp[i] > len) 
                len = dp[i];
        return len;
    }
};
