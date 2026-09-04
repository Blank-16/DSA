class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int maxim = *max_element(nums.begin(), nums.begin() + i + 1);
            int minim = *min_element(nums.begin() + i, nums.end());
            
            if (maxim - minim <= k) {
                return i;
            }
        }
        return -1;
    }
};