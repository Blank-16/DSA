#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        vector<int> temp(nums.size());
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] > nums[i])
            {
                count++;
            }
        }
        if(nums[n-1] > nums[0]) count++;

        return count <= 1;
    }
};