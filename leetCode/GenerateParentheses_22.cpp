class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        back(res, curr, n, 0, 0);
        return res;
    }
    void back(vector<string>& res, string& curr, int n, int open, int close) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            curr += '(';
            back(res, curr, n, open + 1, close);
            curr.pop_back();
        }
        if (close < open) {
            curr += ')';
            back(res, curr, n, open, close + 1);
            curr.pop_back();
        }
    }
};
