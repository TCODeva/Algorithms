/* LeetCode 375. Guess Number Higher or Lower II
 * We are playing the Guess Game. The game is as follows:
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
 * 
 * However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
 * 
 * Example:
 * 
 * n = 10, I pick 8.
 * 
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 * 
 * Game over. 8 is the number I picked.
 * 
 * You end up paying $5 + $7 + $9 = $21.
 * Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
 */
 
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        return helper(dp, 1, n);
    }
    
private:
    int helper(vector<vector<int>>& dp, int head, int tail) {
        if (head >= tail) return 0;
        if (dp[head][tail] != INT_MAX) return dp[head][tail];
        for (int i = head; i <= tail; i++) {
            int sum = i + max(helper(dp, head, i-1), helper(dp, i+1, tail));
            dp[head][tail] = min(dp[head][tail], sum);
        }
        return dp[head][tail];
    }
};

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int j = 2; j <= n; j++){
            for (int i = j-1; i > 0; i--){
                int globalMin = INT_MAX;
                for (int k = i+1; k < j; k++){
                    int localMax = k + max(dp[i][k-1], dp[k+1][j]);
                    globalMin = min(globalMin, localMax);
                }
                dp[i][j] = i + 1 == j ? i : globalMin;
            }
        }
        return dp[1][n];
    }
};
