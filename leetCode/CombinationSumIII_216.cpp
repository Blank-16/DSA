class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> op;
        solve(k, n, op, res, 1);
        return res;
    }
    void solve(int k, int n, vector<int>& op, vector<vector<int>>& res, int i) {
        if (n == 0 && k == 0) {
            res.push_back(op);
            return;
        }
        if (i == 10 || k < 0 || n < 0) {
            return;
        }
        op.push_back(i);
        solve(k - 1, n - i, op, res, i + 1);
        op.pop_back(); // backtracking

        solve(k, n, op, res, i + 1);
        return;
    }
};
