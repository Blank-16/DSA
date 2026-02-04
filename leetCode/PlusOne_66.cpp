class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] + 1 != 10) {
                nums[i] += 1;
                return nums;
            }
            nums[i] = 0;
            if(i == 0) {
                nums.insert(nums.begin(), 1);
                return nums;
            }
        }
        return nums;
    }
};