
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>list(n+1, -1);
        for(int i = 0; i < nums.size(); i++) {
            list[nums[i]] = nums[i];
        }
        for(int i = 0; i < list.size(); i++) {
            if (list[i] != i)  return i;
            else continue;
        }
        return 0;
    }
};