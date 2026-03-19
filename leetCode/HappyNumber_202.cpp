class Solution {
public:
    int getNext(int n) {
        int output = 0;

        while(n > 0) {
            int d = n % 10;
            output += d * d;
            n = n / 10;
        }   
        return output;
    }
    bool isHappy(int n) {
        int slow = getNext(n);
        int fast = getNext(getNext(n));

        while(slow != fast) {
            if(fast == 1) return true;
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return slow == 1;
    }
};
