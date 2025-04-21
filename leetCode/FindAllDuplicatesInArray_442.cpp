
// personal solution sol1

// using sort()

// time complexity: O(nlogn)
// space complexity: O(1)

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return {};
        vector<vector<int>> v;
        vector<int> ans;

        sort(begin(nums), end(nums));
        int s = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == s)
            {
                ans.push_back(nums[i]);
                s = nums[i];
                continue;
            }
            else
            {
                s = nums[i];
                continue;
            }
        }

        return ans;
    }
};




// using unordered_map
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return {};
        vector<int> ans;

        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        for (auto it : mp)
            if (it.second == 2)
                ans.push_back(it.first);

        return ans;
    }
};

