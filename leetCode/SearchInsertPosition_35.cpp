class Solution {
public:
    int bs(vector<int> &nums, int left, int right, int val) {
        if (left > right)
            return left;
        
        int mid = left + (right - left) / 2;

        if (nums[mid] == val)
            return mid;
        else if (val < nums[mid])
            return bs(nums, left, mid - 1, val);
        else
            return bs(nums, mid + 1, right, val);
    }
    int searchInsert(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target);
    }
};
