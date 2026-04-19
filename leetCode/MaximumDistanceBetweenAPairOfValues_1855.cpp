// tle solution

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxim = 0;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                if (nums1[i] <= nums2[j]) {
                    if (maxim < (j - i)) {
                        maxim = j - i;
                    }
                }
            }
        }
        return maxim;
    }
};

// optimized two pointer approach

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxim = 0;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                maxim = max(maxim, j - i);
                j++;
            } else {
                i++;
            }
        }
        return maxim;
    }
};
