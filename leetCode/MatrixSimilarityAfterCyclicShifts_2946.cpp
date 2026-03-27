class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        k = k % m;

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int og;
                if(i % 2 == 0) {
                    og = (j + k) % m;
                } else {
                    og = (j - k + m) % m;
                }
                if (mat[i][j] != mat[i][og]) {
                    return false;
                }
            }
        }
        return true;
    }
};
