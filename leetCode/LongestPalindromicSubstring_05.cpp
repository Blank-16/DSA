/*
 * Two pointer approach
 */



class Solution {
public:
    int expand(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            int odd = expand(s, i, i);
            int even = expand(s, i, i + 1);
            int maxLen = max(odd, even);

            if(maxLen > end - start) {
                start = i - (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};



/* 
 * optimized solution
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string T = "^";
        for (char c : s) {
            T += "#";
            T += c;
        }
        T += "#$";
        int n = T.length();
        vector<int> P(n, 0);
        int C = 0;
        int R = 0;
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * C - i;
            if (i < R) {
                P[i] = min(R - i, P[mirror]);
            }
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
        }
};
