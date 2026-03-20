class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> v;
                for (int x = i; x < i + k; x++)
                    for (int y = j; y < j + k; y++)
                        v.push_back(grid[x][y]);

                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());

                if (v.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int mn = INT_MAX;
                    for (int p = 0; p < (int)v.size() - 1; p++)
                        mn = min(mn, v[p+1] - v[p]);
                    ans[i][j] = mn;
                }
            }
        }
        return ans;
    }
};


// 2d sliding window solution
//
/* To find the minimum absolute difference between any two distinct values in a k×k submatrix, the most efficient way is to look at the values in sorted order. In a sorted list, the minimum difference must exist between two adjacent elements.
Instead of re-scanning the entire k×k block for every possible starting position, we can use a Sliding Window technique. As we move the window one column to the right, we remove the leftmost column of the previous window and add the new rightmost column.

Approach
Outer Loop: We iterate through each possible starting row i for our k×k window.

Initial Window: For each row i, we initialize a std::map<int, int> with the first k×k block. The map automatically keeps the unique values sorted and tracks their frequency.

Inner Loop (Sliding):

Calculate Min Diff: We traverse the map. Since it's sorted, we just check the difference between it and prev. If the map size is 1 (all elements are the same), the answer is 0.
Slide the Window: Before moving to the next column c+1, we update the map by:
Decreasing the count of the k elements in the column we are leaving (grid[r][c]). If a count hits 0, we erase that key.
Increasing the count of the k elements in the new column we are entering (grid[r][c+k]).
Result: Store the minimum difference found for each (i,j) in the ans matrix.

Complexity
Time complexity: O(m⋅n⋅k⋅log(k 
2
 ))
We iterate through m−k+1 rows.
For each row, we slide a window across n−k+1 columns.
In each step, we perform k insertions and k deletions in the map (klog(size)).
We also traverse the map to find the minimum difference, which takes O(k 
2
 ) in the worst case (if all elements are unique), though for 30×30, this is very fast.
Space complexity:O(k 
2
 )
The map stores at most k×k elements at any given time to represent the current submatrix.
*/ 

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i <= n - k; i++) {
            map<int, int> mp;
            for (int r = i; r < i + k; r++) {
                for (int c = 0; c < k; c++) {
                    mp[grid[r][c]]++;
                }
            }
            for (int c = 0; c <= m - k; c++) {
                if (mp.size() > 1) {
                    int mini = 1e9;
                    auto it = mp.begin();
                    int prev = it->first;
                    for (++it; it != mp.end(); it++) {
                        mini = min(mini, abs(it->first - prev));
                        prev = it->first;
                    }
                    ans[i][c] = mini;
                } else {
                    ans[i][c] = 0;
                }

                if (c < m - k) {
                    for (int r = i; r < i + k; r++) {
                        mp[grid[r][c]]--;
                        if (mp[grid[r][c]] == 0)
                            mp.erase(grid[r][c]);
                        mp[grid[r][c + k]]++;
                    }
                }
            }
        }
        return ans;
    }
};






// using radix_sort in 0 ms time frame 

static int kksub[900], INF=2e5+1;
static constexpr int N=512, MASK=511, bshift=9, bias=-1e5;
static int freq[N];

void radix_sort(int* nums, int n) {// 2 rounds
    int* buf=(int*)alloca(n * sizeof(int));
    int* in=nums;
    int* out=buf;

    //1st round
    memset(freq, 0, sizeof(freq));

    for (int i=0; i<n; i++) 
        freq[in[i] & MASK]++;

    partial_sum(freq, freq+N, freq);

    for (int i=n-1; i>=0; i--) {
        const int v=in[i];
        out[--freq[v & MASK]]=v;
    }

    // 2nd round
    memset(freq, 0, sizeof(freq));

    for (int i=0; i<n; i++)
        freq[(out[i]>>bshift) & MASK]++;

    partial_sum(freq, freq+N, freq);

    for (int i=n-1; i>= 0; i--) {
        const int v=out[i];
        in[--freq[(v>>bshift) & MASK]]=v;
    }
}
class TimeOptimised_Solution{
public:
    static vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const int m=grid.size(), n=grid[0].size(), kk=k*k;
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
        const int m0=m-k, n0=n-k;
        for (int i=0; i<=m0; i++) {
            for (int j=0; j<=n0; j++) {
                int idx=0, ik=i+k, jk=j+k;
                for (int x=i; x<ik; x++) {
                    for (int y=j; y<jk; y++) 
                        kksub[idx++]=grid[x][y]-bias;
                }
                radix_sort(kksub, kk);
                int minD=INF;
                for(int a=1; a<kk; a++){
                    int diff=kksub[a]-kksub[a-1];
                    if (diff>0) minD=min(minD, diff);
                }
                ans[i][j]=(minD==INF)?0:minD;
            }
        }
        return ans;
    }
}; 
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
