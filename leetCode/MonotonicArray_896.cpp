class Solution
{
public:
    // pure brute force
    bool isMonotonic(vector<int> &nums)
    {
        vector<int> temp = nums;
        int n = nums.size() - 1;
        if (nums[0] > nums[n])
        {
            sort(temp.begin(), temp.end(), std::greater<>());
        }
        else
        {
            sort(temp.begin(), temp.end());
        }
        return temp == nums;
    }
};

class Solution2
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool increasing = true;
        bool decreasing = true;

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[j - 1])
            {
                increasing = false;
            }
            if (nums[j] > nums[j - 1])
            {
                decreasing = false;
            }
        }

        return increasing || decreasing;
    }
};
