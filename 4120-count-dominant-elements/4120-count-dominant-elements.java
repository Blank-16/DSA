class Solution {
    public int countDominantElements(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return 1;

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (i == 0 && nums[i] >= nums[i + 1] ||
                    i == n - 1 && nums[i] >= nums[i - 1] ||
                    i > 0 && i < n - 1 &&
                            2L * nums[i] >= (long) nums[i - 1] + nums[i + 1]) {
                count++;
            }
        }

        return count;
    }
}