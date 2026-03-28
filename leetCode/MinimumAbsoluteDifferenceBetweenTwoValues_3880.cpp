class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<int> first, second;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                first.push_back(i);
            else if (nums[i] == 2)
                second.push_back(i);
        }

        if (first.empty() || second.empty())
            return -1;

        int i = 0, j = 0;
        int ans = INT_MAX;

        while (i < first.size() && j < second.size()) {
            ans = min(ans, abs(first[i] - second[j]));
            if (first[i] < second[j])
                i++;
            else
                j++;
        }

        return ans;
    }
};
