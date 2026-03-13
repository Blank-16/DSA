class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalElements = n * n;
        vector<int> count(totalElements + 1, 0);
        vector<int> ans(2);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                count[val]++;
                if (count[val] == 2) {
                    ans[0] = val;
                }
            }
        }
        for (int i = 1; i <= totalElements; i++) {
            if (count[i] == 0) {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};
