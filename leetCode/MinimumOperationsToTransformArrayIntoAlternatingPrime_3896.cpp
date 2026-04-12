class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    int nextPrime(int n) {
        while (!isPrime(n))
            n++;
        return n;
    }

    int nextNonPrime(int n) {
        while (isPrime(n))
            n++;
        return n;
    }

    int minOperations(vector<int>& nums) {
        int op = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if (!isPrime(nums[i])) {
                    int target = nextPrime(nums[i]);
                    op += (target - nums[i]);
                }
            } else {
                if (isPrime(nums[i])) {
                    int target = nextNonPrime(nums[i]);
                    op += (target - nums[i]);
                }
            }
        }
        return op;
    }
};
