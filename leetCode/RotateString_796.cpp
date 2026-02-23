class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        if(s.size() != goal.size()) return false;
        int n = s.size(), j = 1;
        while(j < n) {
            char temp = s[n-1];
            for(int i = n - 1; i != 0; i--){
                s[i] = s[i-1];
            }
            s[0] = temp;
            if(s == goal) return true;
            j++;
        }
        return false;
    }
};
