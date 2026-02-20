class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(int d : nums){
            n = n ^ d;
        }
        return n;
    }
};
