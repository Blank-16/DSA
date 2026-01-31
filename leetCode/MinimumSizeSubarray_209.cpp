
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= target) {
                    ans = min(ans, j - i + 1);
                    break; // no need to extend further
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

class Solution2
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (prefix[j] - prefix[i] >= target)
                {
                    ans = min(ans, j - i);
                    break;
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

class Solution3
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int needed = prefix[i] + target;

            auto it = lower_bound(prefix.begin() + i + 1, prefix.end(), needed);

            if (it != prefix.end())
            {
                ans = min(ans, int(it - (prefix.begin() + i)));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};


class Solution4 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
