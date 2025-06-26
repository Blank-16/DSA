
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());        

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            if (i > 0 && a == nums[i-1])
                continue;
            int left = i + 1 , right = nums.size() - 1;
            while(left < right) {
                int sum = a + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } 
                else if (sum < 0) {
                    left++;  
                }
                // for sum = 0
                else {
                    ans.push_back({a, nums[left], nums[right]});
                    left++;
                    while (nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0},
        {1, -1, -1, 0},
        {-2, 0, 1, 1, 2}};

    for (auto &nums : testCases)
    {
        cout << "Input: [";
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i];
            if (i < nums.size() - 1)
                cout << ",";
        }
        cout << "]\nOutput: ";

        vector<vector<int>> result = solution.threeSum(nums);
        cout << "[";
        for (int i = 0; i < result.size(); i++)
        {
            cout << "[";
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << ",";
            }
            cout << "]";
            if (i < result.size() - 1)
                cout << ",";
        }
        cout << "]\n\n";
    }
    return 0;
}