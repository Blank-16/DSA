class Solution {
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.assign(V, 0);

        for (int i = 0; i < V; i++)
            parent[i] = i;

        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        int ans = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (find(u) != find(v)) {
                ans += wt;
                unite(u, v);
            }
        }

        return ans;
    }
};
