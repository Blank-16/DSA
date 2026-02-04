class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0 , right = nums.size() - 1;
        vector<int> ans;
        while(left <= right) {
            if(left == right && nums[left] == val) {
                break;
            }else if(left == right && nums[right] != val) {
                ans.push_back(nums[right]); 
                break;
            }
            if(nums[left] != val) {
                ans.push_back(nums[left]);
                left++;
            }
            if(nums[right] != val) {
                ans.push_back(nums[right]);
                right--;
            }
            if(nums[left] == val) {
                left++;
            }
            if(nums[right] == val) {
                right--;
            }
        }
        nums = ans;
        return ans.size();
    }
};