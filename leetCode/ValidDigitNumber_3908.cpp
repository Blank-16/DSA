class Solution {
public:
    bool validDigit(int n, int x) {
    int original = n;
    int lastDigit = n;

    while (lastDigit >= 10) {
        lastDigit /= 10;
    }
    if (lastDigit == x) return false;

    while (n > 0) {
        if (n % 10 == x) return true;
        n /= 10;
    }

    return false;
    }
};
