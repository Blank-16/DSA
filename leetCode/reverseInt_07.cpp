// reverse integer 07

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        while(x!=0) {
            if( (sum > INT_MAX/10) || (sum < INT_MIN/10) ) {
                return 0;
            }
            sum = (sum * 10) + (x % 10);
            x/=10;            
        }
        return sum;
    }
};

