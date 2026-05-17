class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 1; i < s.size(); i++) {
            int temp = s[i-1] - s[i];
            if(abs(temp) > 2) {
                return false;
            }
        }
        return true;
    }
};
