/* LeetCode 718. Maximum Length of Repeated Subarray
 * Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
 * 
 * Example 1:
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * Note:
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 */
 
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA = A.size(), lenB = B.size(), max = 0;
        vector<vector<int>> dp(lenA+1, vector<int>(lenB+1, 0));
        for (int i = lenA - 1; i >= 0; i--)
            for (int j = lenB - 1; j >= 0; j--) {
                if (A[i] == B[j]) 
                    dp[i][j] = dp[i+1][j+1] + 1;
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        return max;
    }
};
