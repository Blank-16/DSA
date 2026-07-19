class Solution {
public:
    int func(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n, false);
        int ans = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (vis[u])
                continue;

            vis[u] = true;
            ans += cost;

            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    pq.push({func(points[u], points[v]), v});
                }
            }
        }

        return ans;
    }
};