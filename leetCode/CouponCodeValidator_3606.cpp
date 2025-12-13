#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValid(string &code)
    {
        if (code.empty())
        {
            return false;
        }

        for (char &ch : code)
        {
            if (!isalnum(ch) && ch != '_')
            {
                return false;
            }
        }

        return true;
    }
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        unordered_map<string, int> mp = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}};

        vector<pair<int, string>> temp;

        for (int i = 0; i < code.size(); i++)
        {
            if (isActive[i] &&
                mp.count(businessLine[i]) &&
                checkValid(code[i]))
            {
                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }

        sort(begin(temp), end(temp));
        vector<string> result;

        for (auto &it : temp)
        {
            result.push_back(it.second);
        }

        return result;
    }
};

// not my sol
class FastestSol
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        int n = code.size();
        vector<string> ans;
        vector<string> categ = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < n; i++)
        {
            if (!isActive[i])
                continue;
            if (businessLine[i] != categ[0] && businessLine[i] != categ[1] && businessLine[i] != categ[2] && businessLine[i] != categ[3])
                continue;
            int f = 1;
            if (code[i].size() == 0)
                continue;
            for (int j = 0; j < code[i].size(); j++)
            {
                if (!((code[i][j] == '_') || (code[i][j] - 'a' < 26 && code[i][j] - 'a' >= 0) || (code[i][j] - 'A' < 26 && code[i][j] - 'A' >= 0) || (code[i][j] - '0' <= 9 && code[i][j] - '0' >= 0)))
                {
                    f = -1;
                    break;
                }
            }
            if (f == -1)
                continue;
            mp[businessLine[i]].push_back(code[i]);
        }
        for (int i = 0; i < 4; i++)
        {
            auto it = mp.find(categ[i]);
            if (it == mp.end())
                continue;
            sort(it->second.begin(), it->second.end());
            for (int j = 0; j < it->second.size(); j++)
            {
                ans.push_back(it->second[j]);
            }
        }
        return ans;
    }
};