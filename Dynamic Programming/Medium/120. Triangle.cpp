/* LeetCode 120. Triangle
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
 
2-D:

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for (int i = 1; i < triangle.size(); i++) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            for (int j = 1; j < i; j++)
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
        int sum = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) 
            sum = min(sum, dp[triangle.size()-1][i]);
        return sum;
    }
};

1-D:

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--) 
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            dp[0] = dp[0] + triangle[i][0];
        }
        int sum = INT_MAX;
        for (int i = 0; i < dp.size(); i++) 
            sum = min(sum, dp[i]);
        return sum;
    }
};
