
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int total = 0;
        for(int i = 0; i < nums.size(); i++) total += nums[i];
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int rightSum = total - nums[i] - leftSum;
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};