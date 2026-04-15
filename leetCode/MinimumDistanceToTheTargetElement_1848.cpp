class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                int val = abs(start - i);
                if(val < ans) {
                    ans = val;
                }
            }
        }
        return ans;
    }
};
