class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<bool> vec(m+1, false);
        vector<vector<bool>> dp(n + 1, vec);
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            } else {
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};