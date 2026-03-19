// diag[diagonal_id][index]
// 50x50 grid, max i+j is 98, max i-j is 49
unsigned diag[150][51], antid[150][51]; 
const int OFFSET=50;

class Solution {
public:
    static inline int rhombusSum(int i, int j, int d, vector<vector<int>>& grid) {
        if (d==0) return grid[i][j];
        
        const int l=j-d, r=j+d, u=i-d, b=i+d ;
        
        // Diagonals with corner (\) 
        // sum=diag[id][end]-diag[id][start]
        const int i0=u-j+OFFSET, i1=i-l+OFFSET;
        int sum=diag[i0][r+1]-diag[i0][j];
        sum+=diag[i1][j+1]-diag[i1][l];
        
        // Anti-diagonals without corners (/) 
        const int j0=u+j, j1=b+j;
        sum+=antid[j0][i]-antid[j0][u+1];
        sum+=antid[j1][b]-antid[j1][i+1];

        return sum;
    }

    static vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int m=grid.size(), n=grid[0].size();
        
        memset(diag, 0, sizeof(diag));
        memset(antid, 0, sizeof(antid));

        for (int i=0; i< m; i++) {
            for (int j = 0; j < n; j++) {
                const int i0=i-j+OFFSET, j0=i+j;
                const int x=grid[i][j];
                // diag over j, antid over i
                diag[i0][j+1]=diag[i0][j]+x;
                antid[j0][i+1]=antid[j0][i]+x;
            }
        }

  
        int dM=min(m, n)/2; 
        vector<int> x(3, -1);
        for (int d=0; d<=dM; d++) {
            for (int i=d; i<m-d; i++) {
                for (int j=d; j<n-d; j++) {
                    const int y=rhombusSum(i, j, d, grid);

                    // Skip if y is already in our top 3 
                    if (y==x[0] || y==x[1] || y==x[2]) continue;

                    if (y>x[0]) {
                        x[2]=x[1];
                        x[1]=exchange(x[0], y);
                    }
                    else if (y>x[1]) 
                        x[2]=exchange(x[1], y);
                    else if (y>x[2]) 
                        x[2]=y;
                }
            }
        }
        for(int i=2; i>=0; i--) 
            if (x[i]==-1) x.pop_back();
        return x;
    }
};


class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> st;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // size 0 rhombus
                st.insert(grid[i][j]);

                for(int k = 1; ; k++) {

                    int r = i + 2*k;
                    int left = j - k;
                    int right = j + k;

                    if(r >= m || left < 0 || right >= n) break;

                    int sum = 0;

                    int x = i, y = j;

                    // top -> right
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + t][y + t];
                    }

                    // right -> bottom
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k + t][y + k - t];
                    }

                    // bottom -> left
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + 2*k - t][y - t];
                    }

                    // left -> top
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k - t][y - k + t];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it) {
            ans.push_back(*it);
        }

        return ans;
    }
};
