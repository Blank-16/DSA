class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans(mp.size());
        int index = 0;
        for (auto x : mp)
        {
            auto temp = x.second;
            for (auto d : temp)
            {
                ans[index].push_back(d);
            }
            index++;
        }
        return ans;
    }
};

class Solution1
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (const string &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &p : m)
        {
            result.push_back(move(p.second));
        }
        return result;
    }
};