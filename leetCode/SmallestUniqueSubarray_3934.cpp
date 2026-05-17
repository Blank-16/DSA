class Solution {
public:
    int minimumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        for (int len = 1; len <= n; len++) {
            map<vector<int>, int> freq;

            // subarrays of current length
            for (int i = 0; i + len <= n; i++) {
                vector<int> sub(nums.begin() + i, nums.begin() + i + len);
                freq[sub]++;
            }

            // subarray appears exactly once
            for (auto &it : freq) {
                if (it.second == 1)
                    return len;
            }
        }

        return n;
    }
};


/*
 * Optimized using rolling hash
 */

class Solution {
public:
    using ull = unsigned long long;

    bool hasUnique(vector<int>& nums, int len) {
        int n = nums.size();

        const ull base = 911382323;
        unordered_map<ull, int> freq;

        ull hash = 0;
        ull power = 1;

        // Initial hash
        for (int i = 0; i < len; i++) {
            hash = hash * base + nums[i];

            if (i < len - 1)
                power *= base;
        }

        freq[hash]++;

        // Rolling hash
        for (int i = len; i < n; i++) {
            hash -= (ull)nums[i - len] * power;
            hash = hash * base + nums[i];

            freq[hash]++;
        }

        // Check if any subarray appears once
        for (auto& p : freq) {
            if (p.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (hasUnique(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};©leetcode
