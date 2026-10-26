class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int uniqueLen = 9;
        int total = 10;
        for(int i = 2; i <= n; i++) {
            uniqueLen *= (11-i);
            total += uniqueLen;
        }
        return total;
    }
}