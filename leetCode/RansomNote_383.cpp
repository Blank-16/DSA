class Solution
{
public:
    bool canConstruct(string rn, string m)
    {
        if (rn.size() > m.size())
            return false;
        vector<int> f(26, 0);
        for (auto s : rn)
            f[s - 'a']++;
        for (auto s : m)
        {
            if (f[s - 'a'] > 0)
            {
                f[s - 'a']--;
            }
        }
        // int a = *maximum_sum(f.begin(), f.end());
        if (*max_element(f.begin(), f.end()) == 0)
            return true;
        return false;
    }
};

class Solution1
{
public:
    bool canConstruct(string rn, string m)
    {
        if (rn.size() > m.size())
            return false;
        vector<int> f(26, 0);
        for (auto c : m)
            f[c - 'a']++;

        for (auto c : rn)
            if (f[c - 'a']-- <= 0)
                return false;

        return true;
    }
};