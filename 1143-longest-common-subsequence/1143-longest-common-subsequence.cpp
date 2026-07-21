class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.size(), 0);

        int longest = 0;

        for(char c : text2 ) {
            int curLen = 0;
            for(int i = 0; i < dp.size(); i++) {
                if(curLen < dp[i]) 
                    curLen = dp[i];
                else if (c == text1[i]) {
                    dp[i] = curLen + 1;
                    longest = max(longest, curLen + 1);
                }
            }
        }
        return longest;
    }
};