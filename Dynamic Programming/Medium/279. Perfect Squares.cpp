/* LeetCode 279. Perfect Squares
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * Example 2:
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
 
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        for (int i = 1; i <= n; i++) {
            int q = sqrt(i);
            if (i == q * q) {
                dp[i] = 1; 
                continue;
            }
            for (int j = 1; j <= q; j++)
                dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
        return dp[n];
    }
};

class Solution {  
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n * sqrt_n == n);  
    }
    
public:
    // Based on Lagrange's Four Square theorem, there are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n) 
    {  
        // If n is a perfect square, return 1.
        if (is_square(n)) 
            return 1;  
        
        // The result is 4 if and only if n can be written in the form of 4^k*(8*m+7). Please refer to Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0  
            n >>= 2;  
        if ((n & 7) == 7) // n%8 == 7
            return 4;
        
        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
            if (is_square(n - i*i)) 
                return 2;  
        
        return 3;  
    }  
}; 
