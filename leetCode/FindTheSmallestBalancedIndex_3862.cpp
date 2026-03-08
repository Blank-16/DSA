class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long sum  = accumulate(nums.begin(),nums.end(),0LL) - nums[n-1];
        long long prod = 1;
        if(sum == prod) return n-1;
        for(int i = n-2;i>=0;i--){
            prod *= nums[i+1];
            sum -= nums[i];
            if(sum == prod) return i;
            else if(sum < prod) break;
        }
        return -1;
    }
};
