class Solution {
public:
    bool isvalid(vector<pair<int, int>>& visited, int l, int k) {
        for (auto ele : visited) {
            if (ele.second == k || abs(ele.first - l) == abs(ele.second - k)) {
                return false;
            }
        }

        return true;
    }

    void comb(vector<vector<string>>& ans, vector<pair<int, int>>& visited,
              int row, vector<string>& curr, int n) {
        if (row == n) {
            ans.push_back(curr);
            return;
        }

        string now(n, '.');
        for (int i = 0; i < n; i++) {
            if (isvalid(visited, row, i)) {
                visited.push_back({row, i});
                now[i] = 'Q';
                curr.push_back(now);
                comb(ans, visited, row + 1, curr, n);
                curr.pop_back();
                now[i] = '.';
                visited.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<pair<int, int>> visited;
        vector<string> curr;
        comb(ans, visited, 0, curr, n);

        return ans;
    }
};
