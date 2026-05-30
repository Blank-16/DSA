class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> freq(26, 0);
        for(char c : s) 
            freq[c - 'a']++;
        for(int i = 0;i < s.size(); ++i) {
            if(freq[s[i] - 'a'] < k) {
                int left = longestSubstring(s.substr(0 , i) , k);
                int right = longestSubstring(s.substr(i + 1) , k);
                return max(left , right);
            }
        }
        return s.size();
    }
};


/* 
 * fastest sol
 */

class Solution {
public:
    int longest(int start,int end,string s,int k){
        unordered_map<char,int> mp;
        if(end-start+1 < k) return 0;
        for(int i = start; i <= end; i++){
            mp[s[i]]++;
        }
        for(int i=start; i <= end; i++){

            if(mp[s[i]] < k){
                int j = i;
                while(j <= end && mp[s[j]] < k){
                    j++;
                }
                return max(longest(start,i-1,s,k),longest(j,end,s,k));
            }
            
        }
        return end-start+1;
    }
    int longestSubstring(string s, int k) {
        return longest(0,s.size()-1,s,k);
    }
};
