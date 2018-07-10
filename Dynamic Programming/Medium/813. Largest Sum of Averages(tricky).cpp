/* LeetCode 813. Largest Sum of Averages
 * We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not necessarily integers.
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * Note:
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 */
 
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        
        int n = A.size();
        vector<double> p(n+1, 0);
        for (int i = 0; i < n; i++)
            p[i+1] = p[i] + A[i];

        vector<double> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = (p[n] - p[i]) / (n - i);

        for (int k = 0; k < K-1; k++)
            for (int i = 0; i < n; i++)
                for (int j = i+1; j < n; j++)
                    dp[i] = max(dp[i], (p[j] - p[i]) / (j - i) + dp[j]);

        return dp[0];
    }
};
