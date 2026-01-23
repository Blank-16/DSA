
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

class Solution2 {
public:
    bool isPalindrome(string s) {
        vector<int> temp;
        for(char c : s)
        {
            if(isalnum(c))
            {
                temp.push_back(tolower(c));
            }
        }
        int left = 0, right = temp.size() - 1;

        while(left < right) {
            if(temp[left] == temp[right]){
                left++; 
                right--;
            }else {
                return false;
            }
        }
        return true;
    }
};

class OPT
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            while (left < right && !isalnum(static_cast<unsigned char>(s[left])))
            {
                left++;
            }
            while (left < right && !isalnum(static_cast<unsigned char>(s[right])))
            {
                right--;
            }

            if (tolower(static_cast<unsigned char>(s[left])) !=
                tolower(static_cast<unsigned char>(s[right])))
            {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};
