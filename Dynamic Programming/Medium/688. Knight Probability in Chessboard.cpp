/* LeetCode 688. Knight Probability in Chessboard
 * On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
 * 
 * A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
 * 
 * 
 * Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
 * 
 * The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.
 * 
 * Example:
 * Input: 3, 2, 0, 0
 * Output: 0.0625
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
 * From each of those positions, there are also two moves that will keep the knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * Note:
 * N will be between 1 and 25.
 * K will be between 0 and 100.
 * The knight always initially starts on the board.
 */
 
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int moves[8][2] = {{1,2}, {-1,2},{1,-2}, {-1,-2}, {2,1}, {-2,1}, {2,-1}, {-2,-1}};
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K + 1, -1.0)));
        return helper(N, K, r, c, moves, dp);
    }
    
private:
    double helper(int N, int K, int r, int c, int moves[8][2], vector<vector<vector<double>>>& dp) {
        if (0 <= r && r < N && 0 <= c && c < N) {
            if (K == 0) return 1.0;
            if (dp[r][c][K] != -1.0) return dp[r][c][K];
            double p = 0;
            for (int i = 0; i < 8; i++) 
                p += helper(N, K - 1, r + moves[i][0], c + moves[i][1], moves, dp); 
            dp[r][c][K] = p / 8.0;
            return dp[r][c][K];
        }
        return 0;
    }
};
