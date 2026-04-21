class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int n : nums2) {
            while (!st.empty() && st.top() < n) {
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        vector<int> res;
        for (int n : nums1) {
            res.push_back(mp.count(n) ? mp[n] : -1);
        }
        return res;
    }
};


// optimized  { how tf :) }
// ahh makes sense now 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int k = j+1;
                    if(j == nums2.size()-1){
                        ans.push_back(-1);
                        break;
                    }
                    while(k<nums2.size()){
                        if(nums2[k] > nums2[j]){
                            ans.push_back(nums2[k]);
                            break;
                        } 
                        k++;
                    }
                    if(k == nums2.size()){
                        ans.push_back(-1);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
