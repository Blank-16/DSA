class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long sum = 0;

            for (int x : nums)
                sum += (x + mid - 1) / mid;

            if (sum <= threshold) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
