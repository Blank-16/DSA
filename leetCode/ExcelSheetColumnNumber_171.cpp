class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for(char c : columnTitle) {
            sum = sum * 26 + (c - 'A' + 1);
        }
        return sum;
    }
};


