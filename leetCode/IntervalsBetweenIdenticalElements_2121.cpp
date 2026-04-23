class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> ans(n, 0);

        // Store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Process each group
        for (auto &p : mp) {
            vector<int> &idx = p.second;
            int m = idx.size();

            // Prefix sum of indices
            vector<long long> prefix(m, 0);
            prefix[0] = idx[0];
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + idx[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                // Left contribution
                if (i > 0) {
                    left = (long long)idx[i] * i - prefix[i - 1];
                }

                // Right contribution
                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - (long long)idx[i] * (m - i - 1);
                }

                ans[idx[i]] = left + right;
            }
        }

        return ans;
    }
};
