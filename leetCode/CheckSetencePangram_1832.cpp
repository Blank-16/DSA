
class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26)
            return false;
        vector<int> count(26, 0);
        for (int i = 0; i < sentence.size(); i++) {
            count[sentence[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] <= 0) {
                return false;
            }
        }
        return true;
    }
};

class BetterSol
{
public:
    bool checkIfPangram(string sentence)
    {
        bool pre[26] = {0};
        int count = 0;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (!pre[sentence[i] - 'a'])
            {
                count++;
                pre[sentence[i] - 'a'] = 1;
            }
            if (count == 26)
                return true;
        }
        return count == 26;
    }
};