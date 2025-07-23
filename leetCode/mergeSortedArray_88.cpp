#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0)
        {
            return;
        }
        for (int i = 0, a = m; i < nums2.size(); a++, i++) {
            nums1[a] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};