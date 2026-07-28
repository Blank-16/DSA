class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = (N << 1) - 1;

        vector<vector<int>> dp(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];

        for (int n = 1; n < M; n++) {
            for (int i = N - 1; i >= 0; i--) {
                for (int p = N - 1; p >= 0; p--) {
                    int j = n - i;
                    int q = n - p;

                    if (j < 0 || j >= N || q < 0 || q >= N ||
                        grid[i][j] == -1 || grid[p][q] == -1) {
                        dp[i][p] = -1;
                        continue;
                    }

                    int best = dp[i][p];

                    if (i > 0)
                        best = max(best, dp[i - 1][p]);
                    if (p > 0)
                        best = max(best, dp[i][p - 1]);
                    if (i > 0 && p > 0)
                        best = max(best, dp[i - 1][p - 1]);

                    if (best < 0) {
                        dp[i][p] = -1;
                    } else {
                        dp[i][p] = best + grid[i][j];
                        if (i != p)
                            dp[i][p] += grid[p][q];
                    }
                }
            }
        }

        return max(dp[N - 1][N - 1], 0);
    }
};