class Solution {
  public:
    vector<string> NBitBinary(int n) {
        // Your code goes here
        string t = "";
        int one = n, zero = n;
        vector<string> ans;
        solve(one , zero , n , t , ans);
        return ans;
    }
    
    void solve(int one , int zero , int n , string t, vector<string> &ans) {
        if(n == 0) {
            ans.push_back(t);
            return;
        }
        solve(one - 1, zero, n - 1, t + '1', ans);
        if(zero > one) {
            solve(one, zero - 1, n-1, t + '0', ans);
        }
    }
};
