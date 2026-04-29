class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(nums.size()==k) return "0";
        string ans ="";

        // remove previous digits while they are greater than current
        for(int i=0;i<nums.size();i++){
            while(!ans.empty() && k>0 && ans.back()>nums[i]){
                ans.pop_back();
                k--;
            }
            ans+=nums[i];
        }
    
        // remove remaining k digits from end
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        // remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i); 
        
        return ans.empty() ? "0" : ans;
    }
};  
