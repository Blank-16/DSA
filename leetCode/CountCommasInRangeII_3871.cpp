class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        long long start = 1000;
        int c = 1;
        while(start <= n) {
            long long end = start * 1000 - 1;
            long long count = min(n, end) - start + 1;
            ans += count * c;

            start *= 1000;
            c++;
        }
        return ans;
    }
};
