/* LeetCode 576. Out of Boundary Paths
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
 * 
 * Example 1:
 * Input:m = 2, n = 2, N = 2, i = 0, j = 0
 * Output: 6
 * Explanation:
 * 
 * Example 2:
 * Input:m = 1, n = 3, N = 3, i = 0, j = 1
 * Output: 12
 * Explanation:
 * 
 * Note:
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
 */
 
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int moves[4][2] = {{1,0}, {-1,0},{0,1}, {0,-1}};
        vector<vector<vector<long>>> dp(m, vector<vector<long>>(n, vector<long>(N + 1, -1)));
        int M = 1000000000 + 7;
        return helper(m, n, M, N, i, j, moves, dp);
    }
    
private:
    int helper(int m, int n, int M, int N, int r, int c, int moves[4][2], vector<vector<vector<long>>>& dp) {
        if (r < 0 || m <= r || c < 0 || n <= c) return 1;
        else if (N == 0) return 0;
        if (dp[r][c][N] != -1) return dp[r][c][N];
        long p = 0;
        for (int i = 0; i < 4; i++) 
            p += helper(m, n, M, N - 1, r + moves[i][0], c + moves[i][1], moves, dp); 
        dp[r][c][N] = p % M;
        return dp[r][c][N];
    }
};
