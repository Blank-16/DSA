class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==0)  return 0;
        int p1 = 0, p2 = 0;
        for(int n : nums) {
            int tmp = p1;
            p1 = max(p2 + n, p1);
            p2 = tmp;
        }
        return p1;
    }
};