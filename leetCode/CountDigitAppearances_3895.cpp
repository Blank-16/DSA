class Solution {
public:
    int cnt(int n, int digit){
        int count = 0;
        while(n > 0){
            int temp = n % 10;
            if(temp == digit) count++;
            n /= 10;
        }
        return count;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(int n : nums) {
            int temp = cnt(n, digit);
            count += temp;
        }
        return count;
    }
};
