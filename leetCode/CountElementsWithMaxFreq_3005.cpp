#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // since given max numbers is 101 we are creating an array of 101 and updating the array given on the number arriving on nums then updating ans based on how many numbers have same max elements; 

        int freq[101] = {0};
        int max = 0, ans = 0;
        for(int n : nums)
        {
            int f = ++freq[n];
            if(f > max)
            {
                max = f;
                ans = f;
            }
            else if ( max == f)
            {
                ans += f;
            }
        }
        return ans;
    }
};

