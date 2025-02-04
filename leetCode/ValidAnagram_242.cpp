// first solution; 

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> ss , tt;
        for(char c : s){
            ss.push_back(c);
        }
        for(char c : t) {
            tt.push_back(c);
        }
        sort(ss.begin(), ss.end());
        sort(tt.begin(), tt.end());
        for(int i = 0; i < ss.size(); i++) {
            if(ss == tt)
            return true;
            else {
                return false;
            }
        }
        return true;
    }
};

// optimum solution 

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> count(26, 0);
        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) return false;
        }
        return true;
    }
};