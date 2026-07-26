class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
    vector<vector<int>> dp(val.size() + 1, vector<int>(capacity + 1, 0));

    // Calculate maximum profit for each
    // item index and knapsack weight.
    for (int i = val.size() - 1; i >= 0; i--) {
        for (int j = 1; j <= capacity; j++) {

            int take = 0;
            if (j - wt[i] >= 0) {
                take = val[i] + dp[i][j - wt[i]];
            }
            int noTake = dp[i + 1][j];

            dp[i][j] = max(take, noTake);
        }
    }

    return dp[0][capacity];
    }
};
