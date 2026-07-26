class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++) {
            for(int index = 0; index < i; index++) {
                dp[i] = max(dp[i] , dp[index] + price[i - index - 1]);
            }
        }
        return dp[n];
    }
};
