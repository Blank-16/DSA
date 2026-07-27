class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<int> aRow(n, 1);

        for(int i = 1; i < m; i++) {
            vector<int> curr(n, 1);
            for(int j = 1; j < n; j++) {
                curr[j] = curr[j-1] + aRow[j];
            }
            aRow = curr;
        }
        return aRow[n-1];
    }
};