// brute force

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> ans(n);

        if(n == 0 || n == 1) return ans;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& p : mp) {
            cout << p.first << " -> ";
            for (int idx : p.second) {
                cout << idx << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < n; i++) {
            long long distance = 0;
            for(auto &p : mp) {
                if(p.first == nums[i]) {
                    for(auto &e : p.second) {
                        distance += abs(i - e);
                        ans[i] = distance; 
                    }
                }
            }
        }


        return ans;
    }
};

// optimzied 

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
