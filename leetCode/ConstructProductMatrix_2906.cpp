class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        vector<int> flat;
        
        // Flatten
        for (auto &row : grid) {
            for (auto &x : row) {
                flat.push_back(x % mod);
            }
        }

        int size = flat.size();
        vector<int> result(size, 1);

        // Prefix 
        int prefix = 1;
        for (int i = 0; i < size; i++) {
            result[i] = prefix;
            prefix = (prefix * flat[i]) % mod;
        }

        // Suffix 
        int suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            result[i] = (result[i] * suffix) % mod;
            suffix = (suffix * flat[i]) % mod;
        }

        // conversion 
        vector<vector<int>> ans(m, vector<int>(n));
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = result[k++];
            }
        }

        return ans;
    }
};


// code with O(1) extra space except result

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        long long prefix = 1, suffix = 1;
        vector<vector<int>> ans(m, vector<int>(n, 1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = prefix;
                prefix = (prefix * grid[i][j]) % mod;
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                ans[i][j] = (ans[i][j] * suffix) % mod;
                suffix = (suffix * grid[i][j]) % mod;
            }
        }

        return ans;
    }
};
