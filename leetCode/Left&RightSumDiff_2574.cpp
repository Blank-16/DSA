class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int left = 0, sum = 0;
        for (auto &n : nums)
            sum += n;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int right = sum - left - nums[i];
            ans[i] = abs(left - right);
            left += nums[i];
        }
        return ans;
    }
};