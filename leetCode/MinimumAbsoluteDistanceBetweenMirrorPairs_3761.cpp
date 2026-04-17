class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> seen;
        int minDistance = INT_MAX;

        for (int j = 0; j < (int)nums.size(); j++) {
            int rev = reverseNum(nums[j]);

            if (seen.count(nums[j])) {
                minDistance = min(minDistance, j - seen[nums[j]]);
            }

            seen[rev] = j;
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }
};
