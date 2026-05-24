class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        for (int x : nums) {
            if (x == 0)
                zeros++;
        }
        int limit = n - zeros;
        int ans = 0;
        for (int i = 0; i < limit; i++) {
            if (nums[i] == 0)
                ans++;
        }
        return ans;
    }
};
