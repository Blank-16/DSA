class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector <int> mp(201, 0);
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] + 100]++;
        }
        sort(nums.begin(), nums.end(), [&] (int a, int b) {
            if (mp[a + 100] == mp[b + 100]) {
                return a > b;
            }
            return mp[a + 100] < mp[b + 100];
        });
        return nums;
    }
};
