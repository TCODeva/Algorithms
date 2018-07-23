/* LeetCode 464. Can I Win
 * In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who  first causes the running total to reach or exceed 100 wins.
 * 
 * What if we change the game so that players cannot re-use integers?
 * 
 * For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
 * 
 * Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
 * 
 * You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
 * 
 * Example
 * 
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 * 
 * Output:
 * false
 * 
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
 * Same with other integers chosen by the first player, the second player will always win.
 */
 
/* For short notation, let M = maxChoosableInteger and T = desiredTotal.
 * 
 * Key Observation: the state of the game is completely determined by currently available numbers to pick in the common pool.
 * 
 * State of Game: initially, we have all M numbers [1, M] available in the pool. Each number may or may not be picked at a state of the game later on, so we have maximum 2^M different states. Note that M <= 20, so int range is enough to cover it. For memorization, we define int k as the key for a game state, where
 * 
 * the i-th bit of k, i.e., k&(1<<i) represents the availability of number i+1 (1: picked; 0: not picked).
 * At state k, the current player could pick any unpicked number from the pool, so state k can only go to one of the valid next states k':
 * 
 * if i-th bit of k is 0, set it to be 1, i.e., next state k' = k|(1<<i).
 * Recursion: apparently
 * 
 * the current player can win at state k iff opponent can't win at some valid next state k'.
 * Memorization: to speed up the recursion, we can use a vector<int> m of size 2^M to memorize calculated results m[k] for state key k:
 * 
 * 0 : not calculated yet;
 * 1 : current player can win;
 * -1: current player can't win.
 * Initial State Check:
 * There are several checks to be done at initial state k = 0 for early termination so we won't waste our time for DFS process:
 * 
 * if T < 2, obviously, the first player wins by simply picking 1.
 * if the sum of entire pool S = M*(M+1)/2 is less than T, of course, nobody can reach T.
 * if the sum S == T, the order to pick numbers from the pool is irrelevant. Whoever picks the last will reach T. So the first player can win iff M is odd.
 */
 
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2; // sum of entire pool
        if (maxChoosableInteger >= desiredTotal) return true;
        if (sum < desiredTotal) return false;
        if (sum == desiredTotal) return maxChoosableInteger % 2;
        unordered_map<int, bool> memo;
        return helper(maxChoosableInteger, desiredTotal, 0, memo);
    }
    
private:
    bool helper(int m, int t, int k, unordered_map<int, bool>& memo) {
        if (t <= 0) return false;
        if (memo.count(k)) return memo[k];
        for (int i = 0; i < m; ++i)
            if (!(k&1<<i) && !helper(m, t-i-1, k|1<<i, memo)) return memo[k] = true;   // current player wins
        return memo[k] = false; // current player can't win
    }
};
