#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if(index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude 
    solve(nums, output, index+1, ans);

    // include 
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index +1, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}


// using bits instead of recursion 

vector<vector<int>> subset(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    int totalSubsets = 1 << n; // 2^n subsets
    
    // Iterate through all possible subsets (0 to 2^n - 1)
    for(int mask = 0; mask < totalSubsets; mask++)
    {
        vector<int> subset;
        
        // Check each bit position
        for(int i = 0; i < n; i++)
        {
            // If ith bit is set in mask, include nums[i]
            if(mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        
        ans.push_back(subset);
    }
    
    return ans;
}