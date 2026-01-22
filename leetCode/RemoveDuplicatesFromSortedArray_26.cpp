class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        // in case nums not sorted
        // sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[count-1]){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};