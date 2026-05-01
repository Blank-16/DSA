// trying out prod grade cpp code lol 

#include <vector>
#include <cstdint>
#include <algorithm>

class Solution {
public:
    int64_t maxRotateFunction(const std::vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;

        int64_t sum = 0;
        int64_t F = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            F += static_cast<int64_t>(i) * nums[i];
        }

        int64_t result = F;

        for (int k = 1; k < n; ++k) {
            F = F + sum - static_cast<int64_t>(n) * nums[n - k];
            result = std::max(result, F);
        }

        return result;
    }
};


class NProdSolution{
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long sum = 0;
        long F = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }

        long result = F;

        for (int k = 1; k < n; k++) {
            F = F + sum - n * nums[n - k];
            result = max(result, F);
        }

        return result;
    }
};
