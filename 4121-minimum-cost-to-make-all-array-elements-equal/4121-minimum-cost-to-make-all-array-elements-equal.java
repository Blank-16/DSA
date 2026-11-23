class Solution {
    public long minCost(int[] nums) {
        int n = nums.length;
        long ans = Long.MAX_VALUE;

        for (int l = 0; l < n;) {
            int r = l;

            while (r + 1 < n && nums[r + 1] == nums[l]) {
                r++;
            }

            if (r > 0 && l < n - 1) {
                long cost = (long) nums[l] * (l + n - r - 1);
                ans = Math.min(ans, cost);
            }

            l = r + 1;
        }

        return ans;
    }
}
