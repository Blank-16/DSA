class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> combo;

        solve(ans, combo, candidates, target, 0, 0);

        return ans;
    }

    void solve(vector<vector<int>>& ans, vector<int>& combo,
               vector<int>& candidates, int target, int sum, int i) {

        if (i >= candidates.size() || sum >= target) {

            if (sum == target)
                ans.push_back(combo);

            return;
        }

        combo.push_back(candidates[i]);

        solve(ans, combo, candidates, target, sum + candidates[i], i);

        combo.pop_back();

        solve(ans, combo, candidates, target, sum, i + 1);
    }
};
