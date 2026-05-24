class Solution {
public:
    int dist(int rem, int target, int k) {
        int d = abs(rem - target);
        return min(d, k - d);
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rem(n);
        for (int i = 0; i < n; i++) {
            rem[i] = ((nums[i] % k) + k) % k;
        }
        int ans = INT_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y)
                    continue;
                int cost = 0;
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0)
                        cost += dist(rem[i], x, k);
                    else
                        cost += dist(rem[i], y, k);
                }
                ans = min(ans, cost);
            }
        }
        return ans;
    }
};
