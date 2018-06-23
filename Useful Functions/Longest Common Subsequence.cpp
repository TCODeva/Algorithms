int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int dp[n+1, m+1];
    for(i = 0; i <= n; i++) dp[i][0] = 0;
    for(j = 0; j <= m; j++) dp[0][j] = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;    
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n+1, m+1];
}
