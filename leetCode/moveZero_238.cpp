#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZero++] = nums[i];
            }
        }
        while (nonZero < nums.size()) {
            nums[nonZero++] = 0;
        }
    }
};