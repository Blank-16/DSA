
class Solution {
public:
    bool isPalindrome(string s) {

        string letters;
        letters.reserve(s.size());

        for (unsigned char c : s) {
            if (isalnum(c))    
                letters += c;
        }
        
        if(letters.size() < 2) return true;        


        transform(letters.begin(), letters.end(), letters.begin(), ::tolower);
        // cout << letters << endl;

        string reverseStr = letters;
        reverse(reverseStr.begin(), reverseStr.end());

        // cout << reverseStr;
        if(letters == reverseStr) return true;
        
        return false;
    }
};