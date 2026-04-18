class Solution {
public:
    int reverseNum(int n) {
        int temp = 0;
        while (n > 0) {
            int l = n % 10;
            temp = temp * 10 + l;
            n /= 10;
        }
        return temp;
    }
    int mirrorDistance(int n) { return abs(n - reverseNum(n)); }
};
