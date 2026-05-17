class Solution {
public:
    long long kthRoot(long long x, int k) {
        long long low = 0, high = 1e9;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            __int128 val = 1;

            for (int i = 0; i < k; i++) {
                val *= mid;
                if (val > x) break;
            }

            if (val <= x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }

    int countKthRoots(int l, int r, int k) {
        long long right = kthRoot(r, k);
        long long left = kthRoot((long long)l - 1, k);

        return (int)(right - left);
    }
};
