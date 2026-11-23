
class Solution {
    public long minCost(int[] nums) {
        long even = 0;
        long odd = Long.MAX_VALUE / 2;

        for (int i = 1; i < nums.length - 1; i++) {
            long x = nums[i];

            long ne = Math.min(even, odd + x);
            long no = Math.min(odd, even + x);

            even = ne;
            odd = no;
        }

        return nums[0] + (long) nums[nums.length - 1] + even;
    }
}
