class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                a--;
                a = max(0, a); // edge case condition so a doesnt go negative 
            }

            else {
                s[a] = s[i];
                a++;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                b--;
                b = max(0, b);
            }

            else {
                t[b] = t[i];
                b++;
            }
        }
        if (a != b)
            return false;
        else {
            for (int i = 0; i < a; i++) {
                if (s[i] != t[i])
                    return false;
            }
            return true;
        }
    }
};

// using the concept of stacks 

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> string1;
        vector<char> string2;

        for (char c : s) {
            if (c == '#') {
                if (!string1.empty())
                    string1.pop_back();
            } else {
                string1.push_back(c);
            }
        }

        for (char c : t) {
            if (c == '#') {
                if (!string2.empty())
                    string2.pop_back();
            } else {
                string2.push_back(c);
            }
        }

        if (string1.size() != string2.size())
            return false;

        for (int i = 0; i < string1.size(); i++) {
            if (string1[i] != string2[i])
                return false;
        }

        return true;
    }
};


// using  two pointer approach  

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        
        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {
            // Find the next valid character in String S
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break; // Found a valid character
                }
            }

            // Find the next valid character in String T
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break; // Found a valid character
                }
            }

            // Compare the characters
            // Case 1: Both pointers are valid and characters match?
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            // Case 2: One string ended but the other didn't?
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            // Move pointers past the current valid characters
            i--;
            j--;
        }

        return true;
    }
};


// Logic WalkthroughOuter Loop: We run while either i or j are still within bounds.Inner Loops (The Logic Fix):We check s[i]. If it is #, we remember that we need to skip a future character (skipS++).If it is a letter but we have skipS > 0, we ignore the letter and decrease the skip count.We repeat this until we land on a character that actually needs to be compared, or i goes below 0.Comparison:If both i and j are valid ($>=0$) but the characters at those indices are different, the strings are not equal.If one index is valid ($>=0$) and the other is invalid ($-1$), it means one string still has characters while the other is empty. They are not equal.Decrement: If characters matched, we assume they are processed and move both indices back by 1.