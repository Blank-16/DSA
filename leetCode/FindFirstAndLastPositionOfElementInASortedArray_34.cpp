class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int k)
    {
        vector<int> ans = {-1, -1};
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (ans[0] != -1 && ans[1] != -1)
                break;
            if (nums[left] == k && ans[0] == -1)
            {
                ans[0] = left;
            }
            if (nums[right] == k && ans[1] == -1)
            {
                ans[1] = right;
            }
            if (ans[0] == -1)
            {
                left++;
            }
            if (ans[1] == -1)
            {
                right--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;        
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return idx;
    }    
};