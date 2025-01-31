/* LeetCode 787. Cheapest Flights Within K Stops
 * There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.
 * 
 * Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
 * 
 * Example 1:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * Output: 200
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
 * Example 2:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 * Note:
 * 
 * The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
 * The size of flights will be in range [0, n * (n - 1) / 2].
 * The format of each flight will be (src, dst, price).
 * The price of each flight will be in the range [1, 10000].
 * k is in the range of [0, n - 1].
 * There will not be any duplicated flights or self cycles.
 */
 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, INT_MAX)));
        int mon = helper(n, flights, src, dst, K, dp);
        return mon == INT_MAX ? -1 : mon;
    }
    
private:
    int helper(int n, vector<vector<int>>& flights, int src, int dst, int K, vector<vector<vector<int>>>& dp) {
        if (src == dst) return 0;
        if (dp[src][dst][K] != INT_MAX) return dp[src][dst][K];
        if (K == 0) {
            for (int i = 0; i < flights.size(); i++) {
                if (flights[i][0] == src && flights[i][1] == dst) {
                    dp[src][dst][K] = flights[i][2];
                    return dp[src][dst][K];
                }
            }
            return INT_MAX;
        }
        
        for (int i = 0; i < flights.size(); i++) {
            if (flights[i][0] == src) {
                int t = helper(n, flights, flights[i][1], dst, K - 1, dp);
                if (t != INT_MAX)
                    dp[src][dst][K] = min(dp[src][dst][K], flights[i][2] + t);
            }
        }
        return dp[src][dst][K];
    }
};
