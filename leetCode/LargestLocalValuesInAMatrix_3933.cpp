/*
 * Brute force
 */

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                int x = matrix[r][c];

                if (x == 0)
                    continue;

                bool ok = true;

                for (int i = max(0, r - x); i <= min(n - 1, r + x) && ok; i++) {
                    for (int j = max(0, c - x); j <= min(m - 1, c + x); j++) {

                        // Ignore cells where both distances are exactly x
                        if (abs(i - r) == x && abs(j - c) == x)
                            continue;

                        if (matrix[i][j] > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok)
                    ans++;
            }
        }

        return ans;
    }
};


/*
 * Optimized 
 */

class BIT2D {
public:
    int n, m;
    vector<vector<int>> bit;

    BIT2D(int n, int m) : n(n), m(m) {
        bit.assign(n + 1, vector<int>(m + 1, 0));
    }

    void add(int x, int y, int val) {
        for(int i = x + 1; i <= n; i += i & -i) {
            for(int j = y + 1; j <= m; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }

    int sum(int x, int y) {
        int res = 0;

        for(int i = x + 1; i > 0; i -= i & -i) {
            for(int j = y + 1; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }

        return res;
    }

    int query(int x1, int y1, int x2, int y2) {

        if(x1 > x2 || y1 > y2)
            return 0;

        return sum(x2, y2)
             - sum(x1 - 1, y2)
             - sum(x2, y1 - 1)
             + sum(x1 - 1, y1 - 1);
    }
};

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<tuple<int,int,int>> cells;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cells.push_back({matrix[i][j], i, j});
            }
        }

        sort(cells.rbegin(), cells.rend());

        BIT2D bit(n, m);

        int ans = 0;
        int idx = 0;

        while(idx < cells.size()) {

            int val = get<0>(cells[idx]);

            vector<pair<int,int>> same;

            while(idx < cells.size() &&
                  get<0>(cells[idx]) == val) {

                same.push_back({
                    get<1>(cells[idx]),
                    get<2>(cells[idx])
                });

                idx++;
            }

            // check BEFORE inserting equal values
            for(auto &[r,c] : same) {

                if(val == 0)
                    continue;

                int r1 = max(0, r - val);
                int c1 = max(0, c - val);

                int r2 = min(n - 1, r + val);
                int c2 = min(m - 1, c + val);

                int cnt = bit.query(r1, c1, r2, c2);

                // remove excluded corners
                vector<pair<int,int>> corners = {
                    {r - val, c - val},
                    {r - val, c + val},
                    {r + val, c - val},
                    {r + val, c + val}
                };

                for(auto &[x,y] : corners) {

                    if(x < 0 || x >= n || y < 0 || y >= m)
                        continue;

                    if(matrix[x][y] > val)
                        cnt--;
                }

                if(cnt == 0)
                    ans++;
            }

            // insert current value positions
            for(auto &[r,c] : same) {
                bit.add(r, c, 1);
            }
        }

        return ans;
    }
};

/*
 * 34 ms fastest solution
 */

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<pair<int, int>> pos[201];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[matrix[i][j]].push_back({i, j});
            }
        }
        vector<int> gt(201, 0);
        int s = 0;
        for (int v = 200; v >= 0; v--) {
            gt[v] = s;
            s += pos[v].size();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = matrix[i][j];
                if (x == 0) continue;

                if (gt[x] == 0) {
                    ans++;
                    continue;
                }

                int r1 = max(0, i - x), r2 = min(n - 1, i + x);
                int c1 = max(0, j - x), c2 = min(m - 1, j + x);
                int a = (r2 - r1 + 1) * (c2 - c1 + 1);
                bool ok = true;

                if (gt[x] < a) {
                    for (int v = x + 1; v <= 200; v++) {
                        for (auto& p : pos[v]) {
                            int k = p.first, l = p.second;
                            if (k >= r1 && k <= r2 && l >= c1 && l <= c2) {
                                if (abs(k - i) == x && abs(l - j) == x)
                                    continue;
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                } else {
                    for (int d = 1; d <= x; d++) {
                        int sl = (d == x) ? j - d + 1 : j - d;
                        int el = (d == x) ? j + d - 1 : j + d;

                        int k = i - d;
                        if (k >= 0 && k < n) {
                            for (int l = sl; l <= el; l++) {
                                if (l >= 0 && l < m && matrix[k][l] > x) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        if (!ok) break;

                        k = i + d;
                        if (k >= 0 && k < n) {
                            for (int l = sl; l <= el; l++) {
                                if (l >= 0 && l < m && matrix[k][l] > x) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        if (!ok) break;

                        int l = j - d;
                        if (l >= 0 && l < m) {
                            for (int r = i - d + 1; r <= i + d - 1; r++) {
                                if (r >= 0 && r < n && matrix[r][l] > x) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        if (!ok) break;

                        l = j + d;
                        if (l >= 0 && l < m) {
                            for (int r = i - d + 1; r <= i + d - 1; r++) {
                                if (r >= 0 && r < n && matrix[r][l] > x) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        if (!ok) break;
                    }
                }
                if (ok) ans++;
            }
        }
        return ans;
    }
};
