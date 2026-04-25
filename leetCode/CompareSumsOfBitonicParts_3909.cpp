class Solution {
public:
    int findPeak(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();

        int peak = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[peak]) {
                peak = i;
            }
        }

        long long ascSum = 0, descSum = 0;

        for (int i = 0; i <= peak; i++) {
            ascSum += nums[i];
        }

        for (int i = peak; i < n; i++) {
            descSum += nums[i];
        }

        if (ascSum > descSum)
            return 0;
        if (descSum > ascSum)
            return 1;
        return -1;
    }
};
