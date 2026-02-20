class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() <= 2) return nums;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] != nums[i+1]) ans.push_back(nums[i]);
            if(nums[i] == nums[i+1]) i++;
        }
        if(ans.size() == 1) ans.push_back(nums[nums.size() - 1]);
        return ans;
    }
};

class Solution2{
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            ans^=nums[i];
        }

        int index=0;
        // find the set bit position
        for(int i=0;i<32;i++){
            if(ans&(1<<i)){
                index=1<<i;
                break;
            }
        }

        int x=0, y=0;
        // grp them and get the answer
        for(int i=0;i<n;i++){
            if(nums[i]&index)
                x^=nums[i];
            else
                y^=nums[i];
        }

        return  {x,y};
    }
};
