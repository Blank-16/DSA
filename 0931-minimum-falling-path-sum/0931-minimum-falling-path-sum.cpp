class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];

                int upRight = INT_MAX;
                if (j < n - 1) {
                    upRight = matrix[i][j] + dp[i - 1][j + 1];
                }

                int upLeft = INT_MAX;
                if (j > 0) {
                    upLeft = matrix[i][j] + dp[i - 1][j - 1];
                }

                dp[i][j] = min({up, upRight, upLeft});
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};